#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        int best = 0;
        for (int r = 0; r < k; ++r) {
            int len = 0;
            bool lastPickedExists = false;
            int lastPicked = 0;
            for (int x : nums) {
                if (!lastPickedExists) {
                    lastPickedExists = true;
                    lastPicked = x;
                    len = 1;
                } else if ((lastPicked + x) % k == r) {
                    ++len;
                    lastPicked = x;
                }
            }
            best = max(best, len);
        }
        return best;
    }
};

void runTest(vector<int> nums, int k, int expected) {
    Solution sol;
    int result = sol.maximumLength(nums, k);
    cout << "Input: nums = { ";
    for (int num : nums) cout << num << " ";
    cout << "}, k = " << k << "\n";
    cout << "Expected: " << expected << ", Got: " << result << "\n";
    cout << (result == expected ? "Passed\n" : "Failed\n") << endl;
}

int main() {
    runTest({1, 2, 3, 4, 5}, 3, 3);
    runTest({5, 9, 7, 11, 13}, 4, 3);
    runTest({1, 3, 5, 7, 9}, 2, 5);
    runTest({1}, 1, 1);
    runTest({1, 2, 3}, 100, 2);

    return 0;
}