#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> result;
        int n = s.size();
        
        for (int i = 0; i < n; i += k) {
            string group = s.substr(i, k);
            if (group.size() < k) {
                group.append(k - group.size(), fill);
            }
            result.push_back(group);
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    string s;
    int k;
    char fill;

    cout << "Enter string: ";
    cin >> s;
    cout << "Enter group size (k): ";
    cin >> k;
    cout << "Enter fill character: ";
    cin >> fill;

    vector<string> result = sol.divideString(s, k, fill);

    cout << "Divided string groups:\n";
    for (const string& group : result) {
        cout << group << endl;
    }

    return 0;
}