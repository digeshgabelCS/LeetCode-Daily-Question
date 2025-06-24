#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> 
using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> result;

        // Iterate through the array to find key occurrences
        for (int j = 0; j < n; ++j) {
            if (nums[j] == key) {
                // For each occurrence, add indices within distance k
                int start = max(0, j - k);
                int end = min(n - 1, j + k);
                for (int i = start; i <= end; ++i) {
                    result.push_back(i);
                }
            }
        }

        // Remove duplicates and sort the result
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());

        return result;
    }
};

int main() {
    vector<int> nums = {3, 4, 9, 1, 3, 9, 5};
    int key = 9;
    int k = 1;

    Solution solution;
    vector<int> result = solution.findKDistantIndices(nums, key, k);

    // Output the result
    cout << "k-distant indices: ";
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;

    return 0;
}