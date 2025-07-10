#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
    const int n = startTime.size();
    vector<int> gaps = getGaps(eventTime, startTime, endTime);
    int ans = 0;

    vector<int> maxLeft(n + 1);   // maxLeft[i] := max(gaps[0..i])
    vector<int> maxRight(n + 1);  // maxRight[i] := max(gaps[i..n])

    // Build prefix max of gaps
    maxLeft[0] = gaps[0];
    for (int i = 1; i < n + 1; ++i)
      maxLeft[i] = max(gaps[i], maxLeft[i - 1]);

    // Build suffix max of gaps
    maxRight[n] = gaps[n];
    for (int i = n - 1; i >= 0; --i)
      maxRight[i] = max(gaps[i], maxRight[i + 1]);

    // Try moving each meeting
    for (int i = 0; i < n; ++i) {
      const int currMeetingTime = endTime[i] - startTime[i];
      const int adjacentGapsSum = gaps[i] + gaps[i + 1];

      // Maximum available free slot excluding the two adjacent gaps of meeting i
      const int availableFree =
          max(i > 0 ? maxLeft[i - 1] : 0,    // max gap to the left
              (i + 2 < n + 1) ? maxRight[i + 2] : 0);  // max gap to the right

      // Check if current meeting can be moved into other available gaps
      const bool canMoveMeeting = currMeetingTime <= availableFree;

      // Update answer: either merge adjacent gaps or move meeting and add its duration
      ans = max(ans, adjacentGapsSum + (canMoveMeeting ? currMeetingTime : 0));
    }

    return ans;
  }

 private:
  // Helper function to get gaps between meetings and at event boundaries
  vector<int> getGaps(int eventTime, const vector<int>& startTime,
                      const vector<int>& endTime) {
    vector<int> gaps;
    gaps.push_back(startTime[0]);  // from 0 to first meeting start
    for (int i = 1; i < startTime.size(); ++i)
      gaps.push_back(startTime[i] - endTime[i - 1]);
    gaps.push_back(eventTime - endTime.back());  // from last meeting end to eventTime
    return gaps;
  }
};

int main() {
  Solution sol;
  int eventTime = 10;
  vector<int> startTime = {1, 4, 7};
  vector<int> endTime = {2, 5, 8};
  
  int result = sol.maxFreeTime(eventTime, startTime, endTime);
  cout << "Maximum free time: " << result << endl;
  return 0;
}