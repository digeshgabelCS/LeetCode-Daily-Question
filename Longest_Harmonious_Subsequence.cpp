#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        int maxLength = 0;
        for (auto& p : count) {
            int num = p.first;
            int freq = p.second;
            if (count.find(num + 1) != count.end()) {
                maxLength = max(maxLength, freq + count[num + 1]);
            }
        }

        return maxLength;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 3, 2, 2, 5, 2, 3, 7};

    int result = solution.findLHS(nums);
    cout << "Length of Longest Harmonious Subsequence: " << result << endl;

    return 0;
}
