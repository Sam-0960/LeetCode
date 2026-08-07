class Solution {
public:
    int bfs(int row , int col,vector<vector<int>>& grid){
        queue<pair<int,int>> q;
        q.push({row,col});
        grid[row][col] = 0;
        int area = 1;
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            
            if(x-1>=0 && grid[x-1][y] == 1){
                grid[x-1][y] = 0;
                q.push({x-1,y});
                area++;
            }
            if(y-1>=0 && grid[x][y-1] == 1){
                grid[x][y-1] = 0;
                q.push({x,y-1});
                area++;
            }
            if(x+1<grid.size() && grid[x+1][y] == 1){
                grid[x+1][y] = 0;
                q.push({x+1,y});
                area++;
            }
            if(y+1<grid[0].size() && grid[x][y+1] == 1){
                grid[x][y+1] = 0;
                q.push({x,y+1});
                area++;
            }

        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size(), m = grid[0].size();
        int maxi = 0;
        for(auto x =0; x<rows; x++){
            for(auto y=0; y<m;y++){
                if(grid[x][y] == 1){
                    maxi = max(maxi, bfs(x,y,grid));
                }
            }
        }
        return maxi;
    }
};