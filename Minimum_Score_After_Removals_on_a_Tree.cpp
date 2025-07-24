#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> tree;
    vector<int> subXOR, in, out;
    int timer = 0;

    void dfs(int node, int parent, const vector<int>& nums) {
        in[node] = timer++;
        subXOR[node] = nums[node];
        for (int nei : tree[node]) {
            if (nei == parent) continue;
            dfs(nei, node, nums);
            subXOR[node] ^= subXOR[nei];
        }
        out[node] = timer++;
    }

    bool isDescendant(int u, int v) {
        return in[u] <= in[v] && out[v] <= out[u];
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        n = nums.size();
        tree.assign(n, vector<int>());
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        subXOR.assign(n, 0);
        in.assign(n, 0);
        out.assign(n, 0);
        dfs(0, -1, nums);

        int totalXOR = subXOR[0];
        int minScore = INT_MAX;

        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int a = i, b = j;
                if (isDescendant(a, b)) {
                    int x = subXOR[b];
                    int y = subXOR[a] ^ subXOR[b];
                    int z = totalXOR ^ subXOR[a];
                    minScore = min(minScore, max({x, y, z}) - min({x, y, z}));
                } else if (isDescendant(b, a)) {
                    int x = subXOR[a];
                    int y = subXOR[b] ^ subXOR[a];
                    int z = totalXOR ^ subXOR[b];
                    minScore = min(minScore, max({x, y, z}) - min({x, y, z}));
                } else {
                    int x = subXOR[a];
                    int y = subXOR[b];
                    int z = totalXOR ^ subXOR[a] ^ subXOR[b];
                    minScore = min(minScore, max({x, y, z}) - min({x, y, z}));
                }
            }
        }

        return minScore;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 5, 5, 4, 11};
    vector<vector<int>> edges = {{0,1},{1,2},{1,3},{3,4}};

    int result = sol.minimumScore(nums, edges);
    cout << "Minimum score after removing two edges: " << result << endl;

    return 0;
}