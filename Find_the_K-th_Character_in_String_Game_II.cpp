#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int n = operations.size();

        vector<long long> lengths(n + 1);
        lengths[0] = 1;  

        for (int i = 0; i < n; ++i) {
            lengths[i + 1] = min(lengths[i] * 2, k);
        }

        int shift = 0;  
        for (int i = n - 1; i >= 0; --i) {
            if (operations[i] == 0) {
                if (k > lengths[i]) {
                    k -= lengths[i];  
                }
            } else {
                if (k > lengths[i]) {
                    k -= lengths[i];       
                    shift = (shift + 1) % 26;  
                }
            }
        }

        char result = 'a' + shift;
        if (result > 'z') result -= 26;
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> operations = {1, 0, 1};
    long long k = 5;

    char result = sol.kthCharacter(k, operations);
    cout << "The " << k << "th character is: " << result << endl;

    return 0;
}