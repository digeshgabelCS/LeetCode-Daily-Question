#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double soupServings(int n) {
        if (n > 4800) return 1.0;

        int m = (n + 24) / 25; 
        vector<vector<double>> dp(m + 1, vector<double>(m + 1, -1.0));
        return dfs(m, m, dp);
    }

private:
    double dfs(int a, int b, vector<vector<double>>& dp) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;           
        if (b <= 0) return 0.0;          

        if (dp[a][b] >= 0) return dp[a][b];

        dp[a][b] = 0.25 * (
            dfs(a - 4, b, dp) +
            dfs(a - 3, b - 1, dp) +
            dfs(a - 2, b - 2, dp) +
            dfs(a - 1, b - 3, dp)
        );
        return dp[a][b];
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter n (mL for each soup): ";
    cin >> n;
    double result = sol.soupServings(n);
    cout << fixed << setprecision(6);
    cout << "Probability: " << result << "\n";
    return 0;
}