#include <iostream>
#include <cctype>  
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string word) {
        if (word.length() < 3) return false;

        bool hasVowel = false;
        bool hasConsonant = false;

        for (char c : word) {
            if (!isalnum(c)) return false;  

            if (isalpha(c)) {
                char lowerC = tolower(c);
                if (lowerC == 'a' || lowerC == 'e' || lowerC == 'i' || lowerC == 'o' || lowerC == 'u') {
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            }
        }

        return hasVowel && hasConsonant;
    }
};

int main() {
    Solution sol;

    string test1 = "abc";
    string test2 = "A2E";
    string test3 = "12a";
    string test4 = "a!";
    string test5 = "aei";
    string test6 = "xyz";
    string test7 = "A1b";

    cout << boolalpha; 
    cout << "Test 1 (\"abc\"): " << sol.isValid(test1) << endl;
    cout << "Test 2 (\"A2E\"): " << sol.isValid(test2) << endl;
    cout << "Test 3 (\"12a\"): " << sol.isValid(test3) << endl;
    cout << "Test 4 (\"a!\"): " << sol.isValid(test4) << endl;
    cout << "Test 5 (\"aei\"): " << sol.isValid(test5) << endl;
    cout << "Test 6 (\"xyz\"): " << sol.isValid(test6) << endl;
    cout << "Test 7 (\"A1b\"): " << sol.isValid(test7) << endl;

    return 0;
}