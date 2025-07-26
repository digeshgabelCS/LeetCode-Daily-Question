#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        long long validSubarrays = 0;
        int maxLeft = 0, secondMaxLeft = 0;

        vector<long long> gains(n + 1, 0);

        vector<vector<int>> conflicts(n + 1);

        for (auto& p : conflictingPairs) {
            int a = p[0], b = p[1];
            conflicts[max(a, b)].push_back(min(a, b));
        }

        for (int right = 1; right <= n; ++right) {
            for (int left : conflicts[right]) {
                if (left > maxLeft) {
                    secondMaxLeft = maxLeft;
                    maxLeft = left;
                } else if (left > secondMaxLeft) {
                    secondMaxLeft = left;
                }
            }

            validSubarrays += (right - maxLeft);

            gains[maxLeft] += (maxLeft - secondMaxLeft);
        }

        long long bestGain = 0;
        for (long long g : gains)
            bestGain = max(bestGain, g);

        return validSubarrays + bestGain;
    }
};

int main() {
    Solution sol;
    int n = 5;
    vector<vector<int>> conflictingPairs = {
        {1, 3}, {2, 5}, {4, 5}
    };

    long long result = sol.maxSubarrays(n, conflictingPairs);
    cout << "Maximum number of valid subarrays: " << result << endl;
    return 0;
}