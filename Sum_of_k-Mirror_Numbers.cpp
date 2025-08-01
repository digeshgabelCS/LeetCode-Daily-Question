#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int rm;             // remaining count of numbers to find
    long long ans = 0;  // accumulated sum of qualifying numbers

    // Converts a string s in base k to base 10,
    // checks if the result is a palindrome in base 10.
    long long tok(string s, int k) {
        long long b = 1, x = 0;
        for (int i = 0; i < s.size(); ++i) {
            x += b * (s[i] - '0');
            b *= k;
        }
        // Check if x is a palindrome in base 10
        auto t = to_string(x);
        for (int i = 0, j = t.size() - 1; i < j; ++i, --j)
            if (t[i] != t[j])
                return 0;
        --rm;
        return x;
    }

    // Depth-first search to generate palindromic numbers in base k
    void dfs(int k, int d, string& s, int i, int j) {
        if (!rm) return;
        if (i > j) {
            ans += tok(s, k);
            return;
        }
        for (int x = (i == 0 ? 1 : 0); x < k; ++x) {
            s[i] = s[j] = '0' + x;
            dfs(k, d, s, i + 1, j - 1);
        }
    }

    // Main function to find the sum of first n numbers
    // palindromic in both base 10 and base k
    long long kMirror(int k, int n) {
        rm = n;
        for (int d = 1; rm; ++d) {
            auto s = string(d, ' ');
            dfs(k, d, s, 0, d - 1);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int k, n;
    cout << "Enter base (k): ";
    cin >> k;
    cout << "Enter number of palindromes (n): ";
    cin >> n;

    long long result = sol.kMirror(k, n);
    cout << "Sum of first " << n << " numbers palindromic in both base 10 and base " << k << " is: " << result << endl;

    return 0;
}