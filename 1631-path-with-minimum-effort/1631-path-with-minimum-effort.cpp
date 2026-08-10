class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();int m = heights[0].size();
        priority_queue<tuple<int, int, int>,vector<tuple<int, int, int>>,greater<tuple<int, int, int>>> pq;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
        effort[0][0] = 0;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto [diff, x, y] = pq.top();
            pq.pop();
            for (auto [dx, dy] : directions) {
                if (x + dx < 0 || y + dy < 0 ||x + dx >= n || y + dy >= m ) continue;
                int edge = abs(heights[x+dx][y+dy] - heights[x][y]);
                int newEffort = max(diff, edge);
                if(effort[x+dx][y+dy] > newEffort){
                    effort[x+dx][y+dy] = newEffort;
                    pq.push({newEffort,x+dx,y+dy});
                }
            }
        }

        return effort[n-1][m-1];
    }
};