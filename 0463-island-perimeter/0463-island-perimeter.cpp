class Solution {
public:
    void bfs(int i , int j,vector<vector<int>>& grid, int& ans,vector<vector<int>>& visited){
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j] = 1;
        while(!q.empty()){
            auto [dx,dy] = q.front();
            q.pop();
            int edges = 0;
            //up
            if(dx-1 >= 0 && grid[dx-1][dy]){
                if(!visited[dx-1][dy]){
                    visited[dx-1][dy] = 1;
                    q.push({dx-1,dy});
                }
            }else edges++;
            //down
            if(dx+1 <grid.size() && grid[dx+1][dy]){
                if(!visited[dx+1][dy]){
                    visited[dx+1][dy] = 1;
                    q.push({dx+1,dy});
                }
            }else edges++;
            //left
            if(dy-1 >= 0 && grid[dx][dy-1]){
                if(!visited[dx][dy-1]){
                    visited[dx][dy-1] = 1;
                    q.push({dx,dy-1});
                }
            }else edges++;
            //right
            if(dy+1 <grid[0].size() && grid[dx][dy+1]){
                if(!visited[dx][dy+1]){
                    visited[dx][dy+1] = 1;
                    q.push({dx,dy+1});
                }
            }else edges++;
            cout<<edges<<endl;
            ans += edges;
        }
        return;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<int>> vis (grid.size(),vector<int>(grid[0].size(),0));
        for(int i = 0 ; i<grid.size() ; i++){
            for(int j = 0 ; j<grid[0].size(); j++){
                if(grid[i][j] && !vis[i][j])
                    bfs(i,j,grid,ans,vis);
            }
        }
        return ans;
    }
};