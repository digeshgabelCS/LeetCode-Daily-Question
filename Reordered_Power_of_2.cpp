#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        static unordered_set<string> powerPatterns = generatePatterns();
        string s = to_string(n);
        sort(s.begin(), s.end());
        return powerPatterns.count(s);
    }

private:
    static unordered_set<string> generatePatterns() {
        unordered_set<string> patterns;
        for (int i = 1; i <= 1e9; i <<= 1) {
            string s = to_string(i);
            sort(s.begin(), s.end());
            patterns.insert(s);
        }
        return patterns;
    }
};

int main() {
    Solution sol;
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (sol.reorderedPowerOf2(n))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}