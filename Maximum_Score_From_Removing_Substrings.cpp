#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        char first1, second1, first2, second2;
        int highScore, lowScore;

        if (x > y) {
            first1 = 'a'; second1 = 'b'; highScore = x;
            first2 = 'b'; second2 = 'a'; lowScore = y;
        } else {
            first1 = 'b'; second1 = 'a'; highScore = y;
            first2 = 'a'; second2 = 'b'; lowScore = x;
        }

        auto removePairs = [](string &s, char first, char second, int score) {
            stack<char> st;
            int total = 0;
            string temp;

            for (char c : s) {
                if (!st.empty() && st.top() == first && c == second) {
                    st.pop();
                    total += score;
                } else {
                    st.push(c);
                }
            }

            while (!st.empty()) {
                temp += st.top();
                st.pop();
            }
            reverse(temp.begin(), temp.end());
            s = temp;

            return total;
        };

        int total = 0;
        total += removePairs(s, first1, second1, highScore);
        total += removePairs(s, first2, second2, lowScore);

        return total;
    }
};

int main() {
    Solution sol;

    string s = "cdbab";
    int x = 4;
    int y = 5;

    int result = sol.maximumGain(s, x, y);

    cout << "Maximum Gain: " << result << endl; // Expected output: 9

    return 0;
}