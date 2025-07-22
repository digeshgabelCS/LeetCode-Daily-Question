#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int left = 0, right = 0;
        int currentSum = 0, maxSum = 0;

        while (right < nums.size()) {
            while (seen.count(nums[right])) {
                seen.erase(nums[left]);
                currentSum -= nums[left];
                left++;
            }
            seen.insert(nums[right]);
            currentSum += nums[right];
            maxSum = max(maxSum, currentSum);
            right++;
        }

        return maxSum;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {4, 2, 4, 5, 6};

    int result = sol.maximumUniqueSubarray(nums);

    cout << "Maximum score of unique subarray: " << result << endl;

    return 0;
}