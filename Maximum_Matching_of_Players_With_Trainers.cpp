#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int i = 0, j = 0, matches = 0;
        int n = players.size(), m = trainers.size();

        while (i < n && j < m) {
            if (players[i] <= trainers[j]) {
                matches++;
                i++;
                j++;
            } else {
                j++;
            }
        }

        return matches;
    }
};

int main() {
    Solution sol;

    vector<int> players = {4, 7, 9};
    vector<int> trainers = {5, 8, 10};

    int result = sol.matchPlayersAndTrainers(players, trainers);

    cout << "Maximum number of matchings: " << result << endl;

    return 0;
}