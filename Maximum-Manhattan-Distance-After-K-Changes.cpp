#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDistance(string s, int k) {
        int result = 0;
        int x = 0, y = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'E') {
                ++x;
            } else if (s[i] == 'W') {
                --x;
            } else if (s[i] == 'N') {
                ++y;
            } else if (s[i] == 'S') {
                --y;
            }

            // Compute the maximum distance at this step
            int distance = min(abs(x) + abs(y) + 2 * k, i + 1);
            result = max(result, distance);
        }

        return result;
    }
};

int main() {
    Solution solution;

    string moves;
    int k;

    cout << "Enter move sequence (only N/S/E/W characters): ";
    cin >> moves;

    cout << "Enter value of k: ";
    cin >> k;

    int maxDist = solution.maxDistance(moves, k);

    cout << "Maximum distance: " << maxDist << endl;

    return 0;
}