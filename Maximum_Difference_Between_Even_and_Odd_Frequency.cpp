#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> freq;

        // Count frequency of each character
        for (char c : s) {
            freq[c]++;
        }

        int maxOdd = INT_MIN;
        int minEven = INT_MAX;

        // Find max odd frequency and min even frequency
        for (auto& p : freq) {
            if (p.second % 2 == 1) {
                maxOdd = max(maxOdd, p.second);
            } else {
                minEven = min(minEven, p.second);
            }
        }

        // If no valid pair exists
        if (maxOdd == INT_MIN || minEven == INT_MAX) {
            return -1;  // No valid pair found
        }

        return maxOdd - minEven;
    }
};

int main() {
    Solution sol;

    string s1 = "aaaaabbc";
    int result1 = sol.maxDifference(s1);
    cout << "Max difference in \"" << s1 << "\": " << result1 << endl;

    string s2 = "abcabcab";
    int result2 = sol.maxDifference(s2);
    cout << "Max difference in \"" << s2 << "\": " << result2 << endl;

    string s3 = "aabbcc";
    int result3 = sol.maxDifference(s3);
    cout << "Max difference in \"" << s3 << "\": " << result3 << endl;

    string s4 = "aaaabbbb";
    int result4 = sol.maxDifference(s4);
    cout << "Max difference in \"" << s4 << "\": " << result4 << endl;

    string s5 = "abc";
    int result5 = sol.maxDifference(s5);
    cout << "Max difference in \"" << s5 << "\": " << result5 << endl;

    return 0;
}