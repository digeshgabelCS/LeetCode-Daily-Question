#include <iostream>
using namespace std;

class Solution {
public:
    char kthCharacter(int k) {
        return findKth(k, 0);
    }

private:
    char findKth(int k, int shift) {
        if (k == 1)
            return (char)('a' + shift % 26);  

        int length = 1;
        while (length < k)
            length *= 2;

        int half = length / 2;

        if (k <= half) {
            return findKth(k, shift);
        } else {
            return findKth(k - half, shift + 1);
        }
    }
};

int main() {
    Solution sol;
    int k;
    cout << "Enter k: ";
    cin >> k;

    char result = sol.kthCharacter(k);
    cout << "The " << k << "th character is: " << result << endl;

    return 0;
}