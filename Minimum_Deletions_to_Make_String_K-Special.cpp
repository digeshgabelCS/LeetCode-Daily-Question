#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freqMap;

        for (char c : word) {
            freqMap[c]++;
        }

        vector<int> freqs;
        for (auto& pair : freqMap) {
            freqs.push_back(pair.second);
        }

        sort(freqs.begin(), freqs.end());

        int n = freqs.size();
        int result = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int deletions = 0;
            int baseFreq = freqs[i];

            for (int j = 0; j < n; ++j) {
                if (freqs[j] > baseFreq + k) {
                    deletions += freqs[j] - (baseFreq + k);
                } else if (freqs[j] < baseFreq) {
                    deletions += freqs[j];
                }
            }

            result = min(result, deletions);
        }

        return result;
    }
};

int main() {
    Solution sol;
    string word;
    int k;

    cout << "Enter the word: ";
    cin >> word;
    cout << "Enter k: ";
    cin >> k;

    int result = sol.minimumDeletions(word, k);
    cout << "Minimum deletions needed to make word k-special: " << result << endl;

    return 0;
}