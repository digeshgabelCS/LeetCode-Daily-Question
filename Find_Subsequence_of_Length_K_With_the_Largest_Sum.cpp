#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> numWithIndex;

        for (int i = 0; i < n; ++i) {
            numWithIndex.push_back({nums[i], i});
        }

        sort(numWithIndex.begin(), numWithIndex.end(), [](auto& a, auto& b) {
            return a.first > b.first;
        });

        vector<pair<int, int>> selected(numWithIndex.begin(), numWithIndex.begin() + k);

        sort(selected.begin(), selected.end(), [](auto& a, auto& b) {
            return a.second < b.second;
        });

        vector<int> result;
        for (auto& p : selected) {
            result.push_back(p.first);
        }

        return result;
    }
};

int main() {
    vector<int> nums = {3, 4, 3, 3};
    int k = 2;
    
    Solution sol;
    vector<int> result = sol.maxSubsequence(nums, k);

    cout << "Max subsequence of length " << k << " is: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}