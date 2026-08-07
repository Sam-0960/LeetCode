class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> distance(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        // in bfs the distance invariant is as soon as we pop a node we get the
        // shortest distance possible to it
        while (!q.empty()) {
            int k = q.size();

            auto [x, y] = q.front();
            q.pop();
            if (x - 1 >= 0 && !vis[x - 1][y] && mat[x - 1][y] == 1) {
                distance[x - 1][y] = distance[x][y] + 1;
                vis[x - 1][y] = 1;
                mat[x - 1][y] = 0;
                q.push({x - 1, y});
            }
            if (x + 1 < n && !vis[x + 1][y] && mat[x + 1][y] == 1) {
                distance[x + 1][y] = distance[x][y] + 1;
                vis[x + 1][y] = 1;
                mat[x + 1][y] = 0;
                q.push({x + 1, y});
            }
            if (y - 1 >= 0 && !vis[x][y - 1] && mat[x][y - 1] == 1) {
                distance[x][y - 1] = distance[x][y] + 1;
                vis[x][y - 1] = 1;
                mat[x][y - 1] = 0;
                q.push({x, y - 1});
            }
            if (y + 1 < m && !vis[x][y + 1] && mat[x][y + 1] == 1) {
                distance[x][y + 1] = distance[x][y] + 1;
                vis[x][y + 1] = 1;
                mat[x][y + 1] = 0;
                q.push({x, y + 1});
            }
        }
        return distance;
    }
};