#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;

        for (int num : arr) {
            freq[num]++;
        }

        int result = -1;

        for (auto& p : freq) {
            if (p.first == p.second) {
                result = max(result, p.first);
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<int> arr1 = {2, 2, 3, 4};
    vector<int> arr2 = {1, 2, 2, 3, 3, 3};
    vector<int> arr3 = {5};

    cout << "Test case 1: " << sol.findLucky(arr1) << endl;  
    cout << "Test case 2: " << sol.findLucky(arr2) << endl; 
    cout << "Test case 3: " << sol.findLucky(arr3) << endl; 

    return 0;
}