#include <bits/stdc++.h>
using namespace std;

/**
 * LeetCode 837. New 21 Game
 *
 * Alice starts with 0 points and draws numbers while she has less than k points.
 * Each draw is random from [1, maxPts].
 * Alice stops when she has k or more points.
 * Return probability that Alice has n or fewer points.
 *
 * Approach:
 * Dynamic Programming with Sliding Window
 *
 * dp[i] = probability of reaching exactly i points
 * windowSum = sum of probabilities of last maxPts valid states
 * If i < k → Alice can still draw, so dp[i] contributes to windowSum
 * If i >= k → Alice stops, so dp[i] contributes to result
 */

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k - 1 + maxPts) return 1.0;

        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;
        double windowSum = 1.0, result = 0.0;

        for (int i = 1; i <= n; i++) {
            dp[i] = windowSum / maxPts;

            if (i < k) {
                // Alice can still draw, so add probability into window
                windowSum += dp[i];
            } else {
                // Alice stops here, add to final result
                result += dp[i];
            }

            if (i - maxPts >= 0) {
                // Remove probability that is out of window range
                windowSum -= dp[i - maxPts];
            }
        }

        return result;
    }
};

// Example usage / testing
int main() {
    Solution sol;
    
    cout << fixed << setprecision(6);
    
    // Test cases from LeetCode
    cout << sol.new21Game(10, 1, 10) << endl;  // Expected: 1.0
    cout << sol.new21Game(6, 1, 10) << endl;   // Expected: 0.6
    cout << sol.new21Game(21, 17, 10) << endl; // Expected: ~0.73278
    
    return 0;
}