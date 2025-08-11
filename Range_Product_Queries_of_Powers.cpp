#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;

        vector<long long> powers;
        for (int i = 0; i < 31; ++i) {
            if (n & (1 << i)) {
                powers.push_back(1LL << i);
            }
        }

        int m = powers.size();
        vector<long long> prefix(m + 1, 1); 
        for (int i = 0; i < m; ++i) {
            prefix[i + 1] = (prefix[i] * powers[i]) % MOD;
        }

        vector<int> ans;
        ans.reserve(queries.size());
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            long long numerator = prefix[r + 1];
            long long denominator = prefix[l];

            long long inv = modPow(denominator, MOD - 2, MOD);
            ans.push_back((numerator * inv) % MOD);
        }

        return ans;
    }

private:
    long long modPow(long long base, long long exp, long long mod) {
        long long res = 1;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }
};

int main() {
    Solution sol;
    int n = 15;
    vector<vector<int>> queries = {{0, 1}, {2, 2}, {0, 2}};

    vector<int> result = sol.productQueries(n, queries);

    cout << "Answers: ";
    for (int x : result) cout << x << " ";
    cout << endl;

    return 0;
}