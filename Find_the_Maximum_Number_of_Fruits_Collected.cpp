#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        return getTopLeft(fruits) + getTopRight(fruits) + getBottomLeft(fruits)
               - 2 * fruits.back().back(); 
    }

private:
    int getTopLeft(const vector<vector<int>>& fruits) {
        const int n = fruits.size();
        int res = 0;
        for (int i = 0; i < n; ++i)
            res += fruits[i][i];
        return res;
    }

    int getTopRight(const vector<vector<int>>& fruits) {
        const int n = fruits.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0][n - 1] = fruits[0][n - 1];

        for (int x = 1; x < n; ++x) {
            for (int y = n - 2; y >= 0; --y) {
                if (x + y >= n - 1) {
                    dp[x][y] = fruits[x][y];
                    int max_val = 0;
                    
                    // Check valid previous positions
                    if (x > 0 && y + 1 < n) max_val = max(max_val, dp[x-1][y+1]);
                    if (x > 0) max_val = max(max_val, dp[x-1][y]);
                    if (y + 1 < n) max_val = max(max_val, dp[x][y+1]);
                    
                    dp[x][y] += max_val;
                }
            }
        }

        return dp[n - 1][0];
    }

    int getBottomLeft(const vector<vector<int>>& fruits) {
        const int n = fruits.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[n - 1][0] = fruits[n - 1][0];

        for (int y = 1; y < n; ++y) {
            for (int x = n - 2; x >= 0; --x) {
                if (x + y <= n - 1) {
                    dp[x][y] = fruits[x][y];
                    int max_val = 0;
                    
                    // Check valid previous positions
                    if (x + 1 < n && y > 0) max_val = max(max_val, dp[x+1][y-1]);
                    if (x + 1 < n) max_val = max(max_val, dp[x+1][y]);
                    if (y > 0) max_val = max(max_val, dp[x][y-1]);
                    
                    dp[x][y] += max_val;
                }
            }
        }

        return dp[0][n - 1];
    }
};
