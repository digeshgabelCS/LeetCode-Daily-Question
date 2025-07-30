#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int maxLen = 0, currentLen = 0;
        
        for (int num : nums) {
            if (num == maxVal) {
                currentLen++;
                maxLen = max(maxLen, currentLen);
            } else {
                currentLen = 0;
            }
        }
        
        return maxLen;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 3, 2, 3, 3, 3};
    int result = sol.longestSubarray(nums);
    cout << "Length of longest subarray with max bitwise AND: " << result << endl;
    return 0;
}