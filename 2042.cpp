/*You are given an integer n. There are n rooms numbered from 0 to n - 1.

You are given a 2D integer array meetings where meetings[i] = [starti, endi] means that a meeting will be held during the half-closed time interval [starti, endi). All the values of starti are unique.

Meetings are allocated to rooms in the following manner:

Each meeting will take place in the unused room with the lowest number.
If there are no available rooms, the meeting will be delayed until a room becomes free. The delayed meeting should have the same duration as the original meeting.
When a room becomes unused, meetings that have an earlier original start time should be given the room.
Return the number of the room that held the most meetings. If there are multiple rooms, return the room with the lowest number.

A half-closed interval [a, b) is the interval between a and b including a and not including b.

 

Example 1:

Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
Output: 0
Explanation:
- At time 0, both rooms are not being used. The first meeting starts in room 0.
- At time 1, only room 1 is not being used. The second meeting starts in room 1.
- At time 2, both rooms are being used. The third meeting is delayed.
- At time 3, both rooms are being used. The fourth meeting is delayed.
- At time 5, the meeting in room 1 finishes. The third meeting starts in room 1 for the time period [5,10).
- At time 10, the meetings in both rooms finish. The fourth meeting starts in room 0 for the time period [10,11).
Both rooms 0 and 1 held 2 meetings, so we return 0. 
Example 2:

Input: n = 3, meetings = [[1,20],[2,10],[3,5],[4,9],[6,8]]
Output: 1
Explanation:
- At time 1, all three rooms are not being used. The first meeting starts in room 0.
- At time 2, rooms 1 and 2 are not being used. The second meeting starts in room 1.
- At time 3, only room 2 is not being used. The third meeting starts in room 2.
- At time 4, all three rooms are being used. The fourth meeting is delayed.
- At time 5, the meeting in room 2 finishes. The fourth meeting starts in room 2 for the time period [5,10).
- At time 6, all three rooms are being used. The fifth meeting is delayed.
- At time 10, the meetings in rooms 1 and 2 finish. The fifth meeting starts in room 1 for the time period [10,12).
Room 0 held 1 meeting while rooms 1 and 2 each held 2 meetings, so we return 1. 
 

Constraints:

1 <= n <= 100
1 <= meetings.length <= 105
meetings[i].length == 2
0 <= starti < endi <= 5 * 105
All the values of starti are unique.*/ 

#include<bits/stdc++.h>
using namespace std;

struct T {
  long endTime;
  int roomId;
};

class Solution {
 public:
  int mostBooked(int n, vector<vector<int>>& meetings) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> count(n);

    ranges::sort(meetings);

    auto compare = [](const T& a, const T& b) {
      return a.endTime == b.endTime ? a.roomId > b.roomId
                                    : a.endTime > b.endTime;
    };
    priority_queue<T, vector<T>, decltype(compare)> occupied(compare);
    priority_queue<int, vector<int>, greater<>> availableRoomIds;

    for (int i = 0; i < n; ++i)
      availableRoomIds.push(i);

    for (const vector<int>& meeting : meetings) {
      const int start = meeting[0];
      const int end = meeting[1];
      // Push meetings ending before this `meeting` in occupied to the
      // `availableRoomsIds`.
      while (!occupied.empty() && occupied.top().endTime <= start)
        availableRoomIds.push(occupied.top().roomId), occupied.pop();
      if (availableRoomIds.empty()) {
        const auto [newStart, roomId] = occupied.top();
        occupied.pop();
        ++count[roomId];
        occupied.push({newStart + (end - start), roomId});
      } else {
        const int roomId = availableRoomIds.top();
        availableRoomIds.pop();
        ++count[roomId];
        occupied.push({end, roomId});
      }
    }

    return ranges::max_element(count) - count.begin();
  }
};