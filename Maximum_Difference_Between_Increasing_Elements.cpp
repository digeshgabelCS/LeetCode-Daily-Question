#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minVal = nums[0];
        int maxDiff = -1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > minVal) {
                maxDiff = max(maxDiff, nums[i] - minVal);
            } else {
                minVal = nums[i];
            }
        }

        return maxDiff;
    }
};

int main() {
    vector<int> nums = {7, 1, 5, 4};

    // Create Solution object
    Solution sol;
    
    // Call maximumDifference and store result
    int result = sol.maximumDifference(nums);

    // Output the result
    cout << "Maximum difference: " << result << endl;

    return 0;
}