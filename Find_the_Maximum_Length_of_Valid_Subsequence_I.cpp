#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        // Step 1: Create a parity array
        vector<int> parity;
        for (int num : nums) {
            parity.push_back(num % 2);  // 0 for even, 1 for odd
        }

        // Case 1: Same parity throughout
        int maxLenSame = 1, currLen = 1;
        for (int i = 1; i < n; ++i) {
            if (parity[i] == parity[i - 1]) {
                currLen++;
            } else {
                currLen = 1;
            }
            maxLenSame = max(maxLenSame, currLen);
        }

        // Case 2: Alternating parity (parity[i] + parity[i - 1]) % 2 == 1
        int maxLenAlt = 1;
        currLen = 1;
        for (int i = 1; i < n; ++i) {
            if ((parity[i] + parity[i - 1]) % 2 == 1) {
                currLen++;
            } else {
                currLen = 1;
            }
            maxLenAlt = max(maxLenAlt, currLen);
        }

        return max(maxLenSame, maxLenAlt);
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {3, 5, 1, 2, 4, 6}; // alternating example
    vector<int> nums2 = {2, 4, 6, 8};       // same parity example
    vector<int> nums3 = {1, 2, 3, 4, 5};    // mixed

    cout << "Test case 1: " << sol.maximumLength(nums1) << endl; // Output: 4
    cout << "Test case 2: " << sol.maximumLength(nums2) << endl; // Output: 4
    cout << "Test case 3: " << sol.maximumLength(nums3) << endl; // Output: 2 or more

    return 0;
}