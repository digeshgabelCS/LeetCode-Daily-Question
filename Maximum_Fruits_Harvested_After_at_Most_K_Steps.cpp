#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        long long currentSum = 0;
        int maxFruits = 0;
        int i = 0;

        for (int j = 0; j < n; ++j) {
            currentSum += fruits[j][1];

            while (i <= j) {
                int leftPos = fruits[i][0];
                int rightPos = fruits[j][0];
                int windowWidth = rightPos - leftPos;
                int extra = min(abs(startPos - leftPos), abs(startPos - rightPos));

                if (windowWidth + extra > k) {
                    currentSum -= fruits[i][1];
                    ++i;
                } else {
                    break;
                }
            }

            maxFruits = max(maxFruits, (int)currentSum);
        }

        return maxFruits;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> fruits = {{2, 4}, {4, 5}, {9, 7}, {10, 2}};
    int startPos = 5;
    int k = 4;

    int result = sol.maxTotalFruits(fruits, startPos, k);
    cout << "Maximum fruits harvested: " << result << endl;

    return 0;
}