#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);

        // For maximum number
        char toReplaceMax = 0;
        for (char c : s) {
            if (c != '9') {
                toReplaceMax = c;
                break;
            }
        }
        string maxStr = s;
        if (toReplaceMax) {
            for (char& c : maxStr) {
                if (c == toReplaceMax) c = '9';
            }
        }
        int maxNum = stoi(maxStr);

        // For minimum number
        char toReplaceMin = s[0];  // Prefer to change first digit to minimize value
        string minStr = s;
        for (char& c : minStr) {
            if (c == toReplaceMin) c = '0';
        }
        int minNum = stoi(minStr);

        return maxNum - minNum;
    }
};

int main() {
    Solution sol;
    int num;

    cout << "Enter a number: ";
    cin >> num;

    int result = sol.minMaxDifference(num);
    cout << "Difference between max and min values after remapping: " << result << endl;

    return 0;
}