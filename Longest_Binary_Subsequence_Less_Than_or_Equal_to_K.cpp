#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int count = 0;
        long long value = 0;
        long long base = 1;

        for (char c : s) {
            if (c == '0') count++;
        }

        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '1') {
                if (value + base <= k) {
                    value += base;
                    count++;
                }
            }
            if (base <= k)
                base <<= 1;
        }

        return count;
    }
};

int main() {
    Solution sol;

    string s = "1001010";
    int k = 5;

    int result = sol.longestSubsequence(s, k);

    cout << "Length of longest subsequence: " << result << endl;

    return 0;
}