#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        string ans;
        vector<int> count(26);
        vector<char> possibleChars;
        queue<string> q{{""}};  // BFS queue initialized with empty string

        // Count occurrences of each character
        for (const char c : s)
            ++count[c - 'a'];

        // Collect characters that appear at least k times
        for (char c = 'a'; c <= 'z'; ++c)
            if (count[c - 'a'] >= k)
                possibleChars.push_back(c);

        // Sort possible characters in descending order for lexicographically largest result
        sort(possibleChars.rbegin(), possibleChars.rend());

        // BFS to build subsequences
        while (!q.empty()) {
            string currSubseq = q.front();
            q.pop();

            // If repeating this subsequence k times exceeds string length, break
            if (currSubseq.length() * k > s.length())
                break;

            for (const char c : possibleChars) {
                string newSubseq = currSubseq + c;
                if (isSubsequence(newSubseq, s, k)) {
                    q.push(newSubseq);
                    // Update answer if new subsequence is longer or lex greater
                    if (newSubseq.length() > ans.length() ||
                        (newSubseq.length() == ans.length() && newSubseq > ans)) {
                        ans = newSubseq;
                    }
                }
            }
        }

        return ans;
    }

private:
    // Check if 'subseq' repeated k times exists as subsequence in 's'
    bool isSubsequence(const string& subseq, const string& s, int k) {
        int i = 0, count = 0;
        for (char c : s) {
            if (c == subseq[i]) {
                ++i;
                if (i == subseq.size()) {
                    i = 0;
                    ++count;
                    if (count == k)
                        return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    string s = "letsleetcode";
    int k = 2;
    string result = solution.longestSubsequenceRepeatedK(s, k);
    cout << "Longest subsequence repeated " << k << " times: " << result << endl;
    return 0;
}
