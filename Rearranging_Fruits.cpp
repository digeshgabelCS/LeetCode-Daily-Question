#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> cnt;

        for (const auto& x : basket1) {
            ++cnt[x];
        }
        for (const auto& x : basket2) {
            --cnt[x];
        }

        int mn = INT_MAX;
        for (unordered_map<int, int>::const_iterator it = cnt.begin(); it != cnt.end(); ++it) {
            mn = min(mn, it->first);
        }

        vector<int> swaps;
        for (unordered_map<int, int>::const_iterator it = cnt.begin(); it != cnt.end(); ++it) {
            int k = it->first;
            int v = it->second;
            if (v % 2 != 0) {
                return -1;
            }

            for (int i = 0; i < abs(v) / 2; ++i) {
                swaps.push_back(k);
            }
        }

        sort(swaps.begin(), swaps.end());
        long long result = 0;
        for (int i = 0; i < swaps.size(); ++i) {
            result += min(swaps[i], mn * 2);
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> basket1 = {1, 2, 2};
    vector<int> basket2 = {2, 3, 1};
    cout << sol.minCost(basket1, basket2) << endl;
    return 0;
}