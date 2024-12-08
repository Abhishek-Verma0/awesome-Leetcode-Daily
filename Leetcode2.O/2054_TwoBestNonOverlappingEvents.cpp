/****2054. Two Best Non-Overlapping Events
Solved
Medium
Topics
Companies
Hint

You are given a 0-indexed 2D integer array of events where events[i] = [startTimei, endTimei, valuei]. The ith event starts at startTimei and ends at endTimei, and if you attend this event, you will receive a value of valuei. You can choose at most two non-overlapping events to attend such that the sum of their values is maximized.

Return this maximum sum.

Note that the start time and end time is inclusive: that is, you cannot attend two events where one of them starts and the other ends at the same time. More specifically, if you attend an event with end time t, the next event must start at or after t + 1.

 

Example 1:

Input: events = [[1,3,2],[4,5,2],[2,4,3]]
Output: 4
Explanation: Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.

Example 2:
Example 1 Diagram

Input: events = [[1,3,2],[4,5,2],[1,5,5]]
Output: 5
Explanation: Choose event 2 for a sum of 5.

Example 3:

Input: events = [[1,5,3],[1,5,1],[6,6,5]]
Output: 8
Explanation: Choose events 0 and 2 for a sum of 3 + 5 = 8.

 

Constraints:

    2 <= events.length <= 105
    events[i].length == 3
    1 <= startTimei <= endTimei <= 109
    1 <= valuei <= 106

 */




#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        int n = events.size();
        vector<int> maxValues(n);
        maxValues[0] = events[0][2];

        for (int i = 1; i < n; ++i) {
            maxValues[i] = max(maxValues[i - 1], events[i][2]);
        }

        int maxSum = 0;

        for (int i = 0; i < n; ++i) {
            int start = events[i][0];
            int value = events[i][2];
            int idx = binarySearch(events, start - 1);

            int currentSum = value;
            if (idx != -1) {
                currentSum += maxValues[idx];
            }

            maxSum = max(maxSum, currentSum);
        }

        return maxSum;
    }

private:
    int binarySearch(vector<vector<int>>& events, int targetEnd) {
        int start = 0, end = events.size() - 1, res = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (events[mid][1] <= targetEnd) {
                res = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        return res;
    }
};