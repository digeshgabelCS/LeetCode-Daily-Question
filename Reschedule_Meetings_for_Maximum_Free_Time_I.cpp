#include <iostream>
#include <vector>
#include <numeric>  
#include <algorithm> 
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> gaps = getGaps(eventTime, startTime, endTime);
        int n = gaps.size();

        if (k + 1 > n)  
            return accumulate(gaps.begin(), gaps.end(), 0);

        int windowSum = accumulate(gaps.begin(), gaps.begin() + k + 1, 0);
        int ans = windowSum;

        for (int i = k + 1; i < n; ++i) {
            windowSum += gaps[i] - gaps[i - k - 1];
            ans = max(ans, windowSum);
        }

        return ans;
    }

private:
    vector<int> getGaps(int eventTime, const vector<int>& startTime, const vector<int>& endTime) {
        vector<int> gaps;

        gaps.push_back(startTime[0]);

        for (int i = 1; i < startTime.size(); ++i) {
            gaps.push_back(startTime[i] - endTime[i - 1]);
        }

        gaps.push_back(eventTime - endTime.back());

        return gaps;
    }
};

int main() {
    Solution sol;

    int eventTime = 20;
    int k = 1;
    vector<int> startTime = {2, 5, 10};
    vector<int> endTime = {4, 7, 12};

    int result = sol.maxFreeTime(eventTime, k, startTime, endTime);
    cout << "Maximum free time: " << result << endl;

    return 0;
}