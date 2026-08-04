class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& visited){
        int m = grid.size(),n = grid[0].size();
        queue<pair<int,int>> q;
        q.push({row,col});
        visited[row][col] = 1;
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            //check up 
            if(x.first-1>=0){
                if(!visited[x.first-1][x.second] && grid[x.first-1][x.second] == '1'){
                    visited[x.first-1][x.second] = 1;
                    q.push({x.first-1,x.second});
                }
            }
            //check down 
            if(x.first+1<m){
                if(!visited[x.first+1][x.second] && grid[x.first+1][x.second] == '1'){
                    visited[x.first+1][x.second] = 1;
                    q.push({x.first+1,x.second});
                }
            }
            //left
            if(x.second-1 >= 0){
                if(!visited[x.first][x.second-1] && grid[x.first][x.second-1] == '1'){
                    visited[x.first][x.second-1] = 1;
                    q.push({x.first,x.second-1});
                }
            }
            //right
            if(x.second+1<n){
                if(!visited[x.first][x.second+1] && grid[x.first][x.second+1] == '1'){
                    visited[x.first][x.second+1] = 1;
                    q.push({x.first,x.second+1});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size(),n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j= 0 ; j<n; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    bfs(i,j,grid,visited);
                    ans++;
                }
            }
        }
        return ans;
    }
};