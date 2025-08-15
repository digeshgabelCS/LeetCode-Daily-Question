#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        // n must be positive
        if (n <= 0) return false;
        
        // Check if n is a power of 2 (only one bit set)
        // and that the single '1' bit is at an even position
        // 0x55555555 in binary: 01010101010101010101010101010101
        return (n & (n - 1)) == 0 && (n & 0x55555555);
    }
};

int main() {
    Solution sol;
    
    // Test cases
    cout << boolalpha;  // print true/false instead of 1/0
    cout << sol.isPowerOfFour(1) << endl;    // true (4^0)
    cout << sol.isPowerOfFour(4) << endl;    // true (4^1)
    cout << sol.isPowerOfFour(16) << endl;   // true (4^2)
    cout << sol.isPowerOfFour(5) << endl;    // false
    cout << sol.isPowerOfFour(64) << endl;   // true (4^3)
    cout << sol.isPowerOfFour(8) << endl;    // false
    
    return 0;
}