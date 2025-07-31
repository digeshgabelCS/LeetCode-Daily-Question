#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result; 
        set<int> curr, next;       

        for (int num : arr) {
            next.clear();
            next.insert(num);
            for (int val : curr) {
                next.insert(val | num);
            }
            curr = next;
            result.insert(curr.begin(), curr.end());
        }

        return result.size();
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 4}; 
    int result = sol.subarrayBitwiseORs(arr);
    cout << "Number of distinct bitwise ORs of all subarrays: " << result << endl;
    return 0;
}