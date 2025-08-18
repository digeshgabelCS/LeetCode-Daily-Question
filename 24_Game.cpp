#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const double EPS = 1e-6;

    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for (int c : cards) nums.push_back((double)c);
        return solve(nums);
    }

private:
    bool solve(vector<double>& nums) {
        int n = nums.size();
        if (n == 1) {
            return fabs(nums[0] - 24.0) < EPS;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                vector<double> next;
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j) next.push_back(nums[k]);
                }

                for (double val : compute(nums[i], nums[j])) {
                    next.push_back(val);
                    if (solve(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }

    vector<double> compute(double a, double b) {
        vector<double> results;
        results.push_back(a + b);
        results.push_back(a - b);
        results.push_back(b - a);
        results.push_back(a * b);
        if (fabs(b) > EPS) results.push_back(a / b);
        if (fabs(a) > EPS) results.push_back(b / a);
        return results;
    }
};

int main() {
    Solution sol;

    vector<int> cards1 = {4, 1, 8, 7};
    vector<int> cards2 = {1, 2, 1, 2};

    cout << (sol.judgePoint24(cards1) ? "true" : "false") << endl;
    cout << (sol.judgePoint24(cards2) ? "true" : "false") << endl; 

    return 0;
}