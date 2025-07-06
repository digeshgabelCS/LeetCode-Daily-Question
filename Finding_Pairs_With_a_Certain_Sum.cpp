#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class FindSumPairs {
public:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> freqNums2;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int num : nums2) {
            freqNums2[num]++;
        }
    }

    void add(int index, int val) {
        int oldVal = nums2[index];
        freqNums2[oldVal]--;  

        nums2[index] += val;
        freqNums2[nums2[index]]++;  
    }

    int count(int tot) {
        int result = 0;
        for (int num : nums1) {
            int complement = tot - num;
            if (freqNums2.count(complement)) {
                result += freqNums2[complement];
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {3, 4, 5};

    FindSumPairs* obj = new FindSumPairs(nums1, nums2);

    int result1 = obj->count(7);
    cout << "Number of pairs with sum 7: " << result1 << endl;

    obj->add(1, 2);

    int result2 = obj->count(7);
    cout << "Number of pairs with sum 7 after add: " << result2 << endl;

    delete obj;

    return 0;
}