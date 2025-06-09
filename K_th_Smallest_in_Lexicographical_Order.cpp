#include <iostream>
#include <algorithm>  // for min()

using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
        long curr = 1;
        k -= 1;  // since we start from number 1

        while (k > 0) {
            long steps = countSteps(n, curr, curr + 1);
            if (steps <= k) {
                curr += 1;
                k -= steps;
            } else {
                curr *= 10;
                k -= 1;
            }
        }

        return curr;
    }

private:
    long countSteps(int n, long n1, long n2) {
        long steps = 0;
        while (n1 <= n) {
            steps += min((long)n + 1, n2) - n1;
            n1 *= 10;
            n2 *= 10;
        }
        return steps;
    }
};

int main() {
    Solution solution;
    int n, k;

    cout << "Enter n and k: ";
    cin >> n >> k;

    int result = solution.findKthNumber(n, k);
    cout << "The " << k << "-th smallest number in lexicographical order is: " << result << endl;

    return 0;
}