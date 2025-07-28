#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0;
        int count = 0;

        for (int num : nums) {
            maxOr |= num;
        }

        function<void(int, int)> dfs = [&](int index, int currentOr) {
            if (index == nums.size()) {
                if (currentOr == maxOr) {
                    count++;
                }
                return;
            }

            dfs(index + 1, currentOr | nums[index]);

            dfs(index + 1, currentOr);
        };

        dfs(0, 0);
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 1};  
    int result = sol.countMaxOrSubsets(nums);
    cout << "Number of subsets with max OR: " << result << endl;
    return 0;
}