
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();

        vector<pair<int,int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        priority_queue<tuple<int,int,int,int>, vector<tuple<int,int,int,int>>, greater<>> minh;
        minh.emplace(0, 0, 0, 0);

        vector<vector<int>> minTime(n, vector<int>(m, INT_MAX));
        minTime[0][0] = 0;

        while (!minh.empty()) {
            auto [currTime, x, y, alt] = minh.top();
            minh.pop();

            if (currTime > minTime[x][y]) continue;
            if (x == n - 1 && y == m - 1) return currTime;

            for (auto [dx, dy] : dir) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                int waitTime = max(moveTime[nx][ny] - currTime, 0);
                int moveCost = (alt % 2 == 0 ? 1 : 2);
                int nextTime = currTime + waitTime + moveCost;

                if (nextTime < minTime[nx][ny]) {
                    minTime[nx][ny] = nextTime;
                    minh.emplace(nextTime, nx, ny, alt + 1);
                }
            }
        }
        return -1;
    }
};