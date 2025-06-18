#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < nums.size(); i += 3) {
            vector<int> triplet = {nums[i], nums[i + 1], nums[i + 2]};
            if (triplet[2] - triplet[0] > k) {
                return {}; 
            }
            result.push_back(triplet);
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 4, 9, 10, 12};
    int k = 3;

    vector<vector<int>> result = sol.divideArray(nums, k);

    if (result.empty()) {
        cout << "It's impossible to divide the array as per the given condition." << endl;
    } else {
        cout << "Divided arrays:" << endl;
        for (const auto& triplet : result) {
            cout << "[ ";
            for (int num : triplet) {
                cout << num << " ";
            }
            cout << "]" << endl;
        }
    }

    return 0;
}