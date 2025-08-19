#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0, result = 0;

        for (int num : nums) {
            if (num == 0) {
                count++;            
                result += count;    
            } else {
                count = 0;          
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums1 = {1,3,0,0,2,0,0,4};
    cout << sol.zeroFilledSubarray(nums1) << endl; 

    vector<int> nums2 = {0,0,0,2,0,0};
    cout << sol.zeroFilledSubarray(nums2) << endl; 

    vector<int> nums3 = {2,10,2019};
    cout << sol.zeroFilledSubarray(nums3) << endl; 
    
    return 0;
}