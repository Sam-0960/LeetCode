class Solution {
public:
    vector<pair<int,int>> dir = {{1,0},{0,1}};
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(); int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1 ) return 0;
        for(auto& x: obstacleGrid)
            for(auto& y: x)
                if(y == 1) y = -1;
        vector<vector<int>> vis(m,vector<int>(n,0));

        vis[0][0] = 1;
        obstacleGrid[0][0] = 1;
        queue<pair<int,int>> q;
        q.push({0,0});

        while(!q.empty()){
            auto [x,y] = q.front(); q.pop();
            for(auto [dx,dy] : dir){
                if(x+dx >= m || y+dy >= n || x+dx < 0 ||y+dy < 0 || obstacleGrid[x+dx][y+dy] == -1) continue;
                obstacleGrid[x+dx][y+dy] += obstacleGrid[x][y];
                if(!vis[x+dx][y+dy]){
                    vis[x+dx][y+dy] = 1;
                    q.push({x+dx,y+dy});
                }
            }
        }
        return obstacleGrid[m-1][n-1];
    }
};