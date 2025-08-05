#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> used(n, false);  // Track which baskets are already used
        int unplaced = 0;

        for (int i = 0; i < n; ++i) {
            bool placed = false;
            for (int j = 0; j < n; ++j) {
                if (!used[j] && baskets[j] >= fruits[i]) {
                    used[j] = true;
                    placed = true;
                    break;
                }
            }
            if (!placed) {
                ++unplaced;
            }
        }

        return unplaced;
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<int> fruits = {4, 2, 7};
    vector<int> baskets = {5, 3, 4};

    int result = sol.numOfUnplacedFruits(fruits, baskets);

    cout << "Number of unplaced fruits: " << result << endl;  // Output: 1

    return 0;
}
