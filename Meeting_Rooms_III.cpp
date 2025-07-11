#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> availableRooms;
        for (int i = 0; i < n; ++i)
            availableRooms.push(i);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> occupiedRooms;

        vector<int> meetingCount(n, 0);

        for (auto& meeting : meetings) {
            long long start = meeting[0], end = meeting[1];

            while (!occupiedRooms.empty() && occupiedRooms.top().first <= start) {
                availableRooms.push(occupiedRooms.top().second);
                occupiedRooms.pop();
            }

            if (!availableRooms.empty()) {
                int room = availableRooms.top();
                availableRooms.pop();
                occupiedRooms.push({end, room});
                meetingCount[room]++;
            }
            else {
                auto nextMeeting = occupiedRooms.top();
                occupiedRooms.pop();
                int room = nextMeeting.second;
                long long newEnd = nextMeeting.first + (end - start);
                occupiedRooms.push({newEnd, room});
                meetingCount[room]++;
            }
        }

        int resultRoom = 50;
        for (int i = 1; i < n; ++i) {
            if (meetingCount[i] > meetingCount[resultRoom])
                resultRoom = i;
        }
        return resultRoom;
    }
};

int main() {
    Solution sol;
    int n = 2;
    vector<vector<int>> meetings = {{0, 10}, {1, 5}, {2, 7}, {3, 4}};
    cout << "Most booked room: " << sol.mostBooked(n, meetings) << endl;
    return 0;
}