#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        int current = 1;

        for (int i = 0; i < n; ++i) {
            result.push_back(current);
            if (current * 10 <= n) {
                current *= 10;  // go down one level
            } else {
                if (current >= n) current /= 10;  // move up if needed
                ++current;
                while (current % 10 == 0) current /= 10;  // move to next valid number
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    int n;

    cout << "Enter n: ";
    cin >> n;

    vector<int> result = solution.lexicalOrder(n);

    cout << "Lexicographical order from 1 to " << n << ":\n";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}