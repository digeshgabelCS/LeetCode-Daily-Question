#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.back() - nums.front();
        int n = nums.size();

        auto canFormPairs = [&](int maxDiff) {
            int count = 0;
            for (int i = 1; i < n;) {
                if (nums[i] - nums[i - 1] <= maxDiff) {
                    count++;
                    i += 2;  // skip both indices to avoid reuse
                } else {
                    i++;
                }
            }
            return count >= p;
        };

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canFormPairs(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 3, 6, 19, 20};
    int p = 2;

    int result = solution.minimizeMax(nums, p);
    cout << "Minimum possible maximum difference among " << p << " pairs is: " << result << endl;

    return 0;
}