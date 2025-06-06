#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<int> count(26, 0);
        for (char c : s) count[c - 'a']++;  // count occurrences of each character

        string t;      // stack representing robot's hand string
        string result; // string on the paper

        int pos = 0; // current index in s

        for (int i = 0; i < n; ++i) {
            // push s[i] to t
            t.push_back(s[i]);
            count[s[i] - 'a']--;

            // try popping from t while top of t is <= smallest remaining character in s
            while (!t.empty()) {
                // find smallest character left in s
                int smallest = 0;
                while (smallest < 26 && count[smallest] == 0) smallest++;

                // if no characters left in s, or top of t <= smallest remaining, pop from t
                if (smallest == 26 || t.back() <= ('a' + smallest)) {
                    result += t.back();
                    t.pop_back();
                } else {
                    break;
                }
            }
        }

        return result;
    }
};

// Example usage
int main() {
    Solution sol;
    string s;

    cout << "Enter a string: ";
    cin >> s;

    string result = sol.robotWithString(s);
    cout << "Resulting string on paper: " << result << endl;

    return 0;
}