#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());

        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        int day = 0, i = 0, n = events.size(), result = 0;

        int lastDay = 0;
        for (const auto& e : events) {
            lastDay = max(lastDay, e[1]);
        }

        for (day = 1; day <= lastDay; ++day) {
            while (i < n && events[i][0] == day) {
                minHeap.push(events[i][1]);  
                ++i;
            }

            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }

            if (!minHeap.empty()) {
                minHeap.pop();
                ++result;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> events = {{1, 2}, {2, 3}, {3, 4}};
    int maxAttendableEvents = sol.maxEvents(events);
    cout << "Maximum number of events that can be attended: " << maxAttendableEvents << endl;
    return 0;
}