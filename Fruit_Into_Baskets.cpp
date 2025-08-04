#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket;
        int left = 0, maxFruits = 0;

        for (int right = 0; right < fruits.size(); ++right) {
            basket[fruits[right]]++;

            while (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0) {
                    basket.erase(fruits[left]);
                }
                left++;
            }

            maxFruits = max(maxFruits, right - left + 1);
        }

        return maxFruits;
    }
};

int main() {
    Solution sol;
    
    vector<int> fruits1 = {1, 2, 1};
    cout << "Max fruits collected: " << sol.totalFruit(fruits1) << endl;  // Output: 3

    vector<int> fruits2 = {0, 1, 2, 2};
    cout << "Max fruits collected: " << sol.totalFruit(fruits2) << endl;  // Output: 3

    vector<int> fruits3 = {1, 2, 3, 2, 2};
    cout << "Max fruits collected: " << sol.totalFruit(fruits3) << endl;  // Output: 4

    vector<int> fruits4 = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    cout << "Max fruits collected: " << sol.totalFruit(fruits4) << endl;  // Output: 5

    return 0;
}