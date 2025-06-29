#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        vector<int> pow2(n, 1);

        // Precompute powers of 2 up to n-1 (since 2^0 to 2^(n-1))
        for (int i = 1; i < n; ++i)
            pow2[i] = (pow2[i - 1] * 2) % MOD;

        sort(nums.begin(), nums.end());

        int left = 0, right = n - 1;
        int result = 0;

        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                result = (result + pow2[right - left]) % MOD;
                ++left;
            } else {
                --right;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<int> nums = {3, 5, 6, 7};
    int target = 9;

    int result = sol.numSubseq(nums, target);
    cout << "Number of valid subsequences: " << result << endl;

    return 0;
}