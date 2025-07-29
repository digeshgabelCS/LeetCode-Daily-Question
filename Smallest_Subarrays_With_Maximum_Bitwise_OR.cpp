#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);  
        vector<int> bitIndex(32, -1);  

        for (int i = n - 1; i >= 0; --i) {
            for (int bit = 0; bit < 32; ++bit) {
                if ((nums[i] >> bit) & 1) {
                    bitIndex[bit] = i;
                }
            }

            int farthest = i;
            for (int bit = 0; bit < 32; ++bit) {
                if (bitIndex[bit] != -1) {
                    farthest = max(farthest, bitIndex[bit]);
                }
            }

            answer[i] = farthest - i + 1;
        }

        return answer;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 0, 2, 1, 3};  
    vector<int> result = sol.smallestSubarrays(nums);

    cout << "Result: ";
    for (int len : result) {
        cout << len << " ";
    }
    cout << endl;

    return 0;
}