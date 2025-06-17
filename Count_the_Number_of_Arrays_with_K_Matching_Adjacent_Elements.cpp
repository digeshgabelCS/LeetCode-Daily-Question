#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countGoodArrays(int n, int m, int k) {
        const int MOD = 1e9 + 7;
        if (k >= n) return 0;

        // Precompute factorials, inverse factorials, and modular inverses
        vector<long long> fact(n + 1);
        vector<long long> invFact(n + 1);
        vector<long long> inv(n + 1);
        fact[0] = invFact[0] = 1;
        inv[0] = inv[1] = 1;

        for (int i = 1; i <= n; ++i) {
            if (i >= 2)
                inv[i] = MOD - MOD / i * inv[MOD % i] % MOD;
            fact[i] = (fact[i - 1] * i) % MOD;
            invFact[i] = (invFact[i - 1] * inv[i]) % MOD;
        }

        // Modular exponentiation function
        auto modPow = [&](long long base, long long exp) {
            long long res = 1;
            base %= MOD;
            while (exp > 0) {
                if (exp % 2 == 1)
                    res = (res * base) % MOD;
                base = (base * base) % MOD;
                exp /= 2;
            }
            return res;
        };

        // Function to compute nCk % MOD
        auto nCk = [&](int n, int k) {
            if (k < 0 || k > n) return 0LL;
            return (fact[n] * invFact[k] % MOD * invFact[n - k] % MOD);
        };

        // Main calculation
        long long result = (long long)m * modPow(m - 1, n - k - 1) % MOD * nCk(n - 1, k) % MOD;
        return (int)result;
    }
};

int main() {
    Solution solution;
    int n, m, k;

    // Sample input
    cout << "Enter values for n, m, and k: ";
    cin >> n >> m >> k;

    int result = solution.countGoodArrays(n, m, k);
    cout << "Number of good arrays: " << result << endl;

    return 0;
}