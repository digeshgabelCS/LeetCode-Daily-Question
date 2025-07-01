#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int possibleStringCount(string word) {
        int f = 1; 

        for (int i = 1; i < word.size(); ++i) {
            f += (word[i] == word[i - 1]); 
        }

        return f;
    }
};

int main() {
    Solution solution;

    // Test cases
    string word1 = "aabb";
    cout << "Possible original strings for \"" << word1 << "\": "
         << solution.possibleStringCount(word1) << endl;

    string word2 = "abc";
    cout << "Possible original strings for \"" << word2 << "\": "
         << solution.possibleStringCount(word2) << endl;

    string word3 = "aaabbaa";
    cout << "Possible original strings for \"" << word3 << "\": "
         << solution.possibleStringCount(word3) << endl;

    string word4 = "a";
    cout << "Possible original strings for \"" << word4 << "\": "
         << solution.possibleStringCount(word4) << endl;

    string word5 = "aaaa";
    cout << "Possible original strings for \"" << word5 << "\": "
         << solution.possibleStringCount(word5) << endl;

    return 0;
}