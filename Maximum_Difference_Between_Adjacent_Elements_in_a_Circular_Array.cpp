#include <iostream>
#include <vector>
#include <cstdlib>   
#include <algorithm> 
using namespace std;

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0; // No adjacent elements to compare

        int maxDiff = 0;

        for (int i = 0; i < n; ++i) {
            int nextIndex = (i + 1) % n; // wrap around for circular adjacency
            int diff = abs(nums[i] - nums[nextIndex]);
            maxDiff = max(maxDiff, diff);
        }
        return maxDiff;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 8, 6, 3};

    int result = sol.maxAdjacentDistance(nums);

    cout << "Maximum absolute difference between adjacent elements: " << result << endl;

    return 0;
}