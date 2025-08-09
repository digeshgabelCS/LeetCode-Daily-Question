#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};

int main() {
    Solution solution;

    int testValues[] = {1, 2, 3, 4, 5, 8, 16, 18, 32, 64, 100};
    for (int n : testValues) {
        cout << "Is " << n << " a power of two? "
             << (solution.isPowerOfTwo(n) ? "Yes" : "No") << endl;
    }

    return 0;
}