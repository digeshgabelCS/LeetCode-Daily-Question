#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        string result;
        int count = 1;  // Start by counting the first character

        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                count++;
            } else {
                count = 1;
            }

            // Only append if less than 3 consecutive characters
            if (count < 3) {
                result += s[i];
            }
        }

        // Add the first character unconditionally if string is not empty
        return s.empty() ? "" : s[0] + result;
    }
};

int main() {
    Solution solution;

    // Example 1
    string input1 = "aaabaaaa";
    cout << "Input: " << input1 << endl;
    cout << "Output: " << solution.makeFancyString(input1) << endl;

    // Example 2
    string input2 = "aab";
    cout << "Input: " << input2 << endl;
    cout << "Output: " << solution.makeFancyString(input2) << endl;

    // Example 3
    string input3 = "a";
    cout << "Input: " << input3 << endl;
    cout << "Output: " << solution.makeFancyString(input3) << endl;

    return 0;
}
