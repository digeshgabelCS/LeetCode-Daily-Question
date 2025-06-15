#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string a = s, b = s;

        // Maximize 'a' by replacing first non-9 digit with 9
        char toReplace = 0;
        for (char c : s) {
            if (c != '9') {
                toReplace = c;
                break;
            }
        }
        if (toReplace) {
            for (char& c : a) {
                if (c == toReplace) c = '9';
            }
        }

        if (s[0] != '1') {
            char oldChar = s[0];
            for (char& c : b) {
                if (c == oldChar) c = '1';
            }
        } else {
            char toReplaceMin = 0;
            for (int i = 1; i < s.size(); ++i) {
                if (s[i] != '0' && s[i] != '1') {
                    toReplaceMin = s[i];
                    break;
                }
            }
            if (toReplaceMin) {
                for (int i = 1; i < b.size(); ++i) {
                    if (b[i] == toReplaceMin) b[i] = '0';
                }
            }
        }

        int maxNum = stoi(a);
        int minNum = stoi(b);

        return maxNum - minNum;
    }
};

int main() {
    Solution sol;

    int num1 = 555;
    cout << "Max difference for " << num1 << " is: " << sol.maxDiff(num1) << endl;

    int num2 = 9;
    cout << "Max difference for " << num2 << " is: " << sol.maxDiff(num2) << endl;

    int num3 = 123456;
    cout << "Max difference for " << num3 << " is: " << sol.maxDiff(num3) << endl;

    return 0;
}