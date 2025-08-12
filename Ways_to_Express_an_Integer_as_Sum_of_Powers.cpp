#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;

    int modPow(int base, int exp) {
        long long result = 1;
        for (int i = 0; i < exp; ++i) {
            result *= base;
            if (result > INT_MAX) return INT_MAX; 
        }
        return (int)result;
    }

    int solve(int curr, int n, int x) {
        if (n == 0) return 1;
        if (n < 0) return 0;

        int power = modPow(curr, x);
        if (power > n) return 0; 

        if (dp[curr][n] != -1) return dp[curr][n];

        long long take = solve(curr + 1, n - power, x) % MOD; 
        long long skip = solve(curr + 1, n, x) % MOD;        

        return dp[curr][n] = (take + skip) % MOD;
    }

    int numberOfWays(int n, int x) {
        dp.assign(n + 2, vector<int>(n + 1, -1));
        return solve(1, n, x);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    int n, x;
    cin >> n >> x; 
    cout << sol.numberOfWays(n, x) << "\n";

    return 0;
}