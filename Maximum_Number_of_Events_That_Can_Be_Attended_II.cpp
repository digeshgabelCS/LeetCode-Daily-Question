#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();

        sort(events.begin(), events.end());

        vector<vector<int>> dp(n, vector<int>(k + 1, -1));

        auto findNext = [&](int index) {
            int left = index + 1, right = n - 1, ans = n;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (events[mid][0] > events[index][1]) {
                    ans = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return ans;
        };

        function<int(int, int)> dfs = [&](int i, int remaining) {
            if (i == n || remaining == 0) return 0;
            if (dp[i][remaining] != -1) return dp[i][remaining];

            int skip = dfs(i + 1, remaining);

            int nextIndex = findNext(i);
            int take = events[i][2] + dfs(nextIndex, remaining - 1);

            return dp[i][remaining] = max(skip, take);
        };

        return dfs(0, k);
    }
};

int main() {
    Solution sol;

    vector<vector<int>> events = {
        {1, 3, 4},
        {2, 5, 3},
        {4, 6, 7},
        {6, 7, 5}
    };
    int k = 2;

    int result = sol.maxValue(events, k);
    cout << "Maximum total value from attending up to " << k << " events: " << result << endl;

    return 0;
}