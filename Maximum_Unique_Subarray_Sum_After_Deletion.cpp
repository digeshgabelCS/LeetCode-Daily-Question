#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> seen;
        int left = 0, currentSum = 0, maxSum = 0;

        for (int right = 0; right < nums.size(); ++right) {
            while (seen.count(nums[right])) {
                seen.erase(nums[left]);
                currentSum -= nums[left];
                left++;
            }

            seen.insert(nums[right]);
            currentSum += nums[right];
            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }
};

int main() {
    vector<int> nums;
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        nums.push_back(val);
    }

    Solution solution;
    int result = solution.maxSum(nums);

    cout << "Maximum sum of unique subarray: " << result << endl;

    return 0;
}