class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m,vector<int>(n,0));
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0] = 1;
        vis[0][0] = 1;
        while(!q.empty()){
            auto [x,y] = q.front(); q.pop();
            if(x+1 < m){
                grid[x+1][y] += grid[x][y];
                if(!vis[x+1][y]){
                    vis[x+1][y] = 1;
                    q.push({x+1,y});
                }
            }
            if(y+1 < n){
                grid[x][y+1] += grid[x][y];
                if(!vis[x][y+1]){
                    vis[x][y+1] = 1;
                    q.push({x,y+1});
                }
            }
        }
        return grid[m-1][n-1];
    }
};