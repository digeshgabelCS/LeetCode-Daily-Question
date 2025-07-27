#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        vector<int> v;
        v.reserve(n);
        v.push_back(nums[0]);
        for (int i = 1; i < n; ++i) {
            if (nums[i] != nums[i - 1]) {
                v.push_back(nums[i]);
            }
        }

        int count = 0;
        int m = v.size();
        for (int i = 1; i < m - 1; ++i) {
            if (v[i] > v[i - 1] && v[i] > v[i + 1]) {
                ++count;
            } else if (v[i] < v[i - 1] && v[i] < v[i + 1]) {
                ++count; 
            }
        }

        return count;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {2, 4, 1, 1, 6, 5};
    vector<int> nums2 = {6, 6, 5, 5, 4, 1};

    cout << "Hills and valleys in nums1: " << sol.countHillValley(nums1) << endl; // Output: 3
    cout << "Hills and valleys in nums2: " << sol.countHillValley(nums2) << endl; // Output: 0

    return 0;
}