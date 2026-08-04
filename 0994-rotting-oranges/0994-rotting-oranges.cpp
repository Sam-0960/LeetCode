class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.size()== 1 && grid[0].size() == 1 && grid[0][0] == 1) return -1;
        queue<pair<int,int>> q;
        int rows = grid.size(), cols = grid[0].size();
        int total = 0;
        for(int i=0; i<rows; i++){
            for(int j = 0 ; j<cols; j++){
                if(grid[i][j] == 2) q.push({i,j});
                if(grid[i][j] == 2 || grid[i][j] == 1) total++;
            }
        }
        if(total == 0) return 0;
        int time = 0;
        while(!q.empty()){
            int n = q.size();
            total -= n;
            ++time;
            for(int i=0;i<n;i++){
                auto [x,y] = q.front();
                q.pop();
                //up
                if(x-1 >= 0 && grid[x-1][y] == 1){
                    grid[x-1][y] = 2;
                    q.push({x-1,y});
                }
                //down
                if(x+1 <grid.size() && grid[x+1][y] == 1){
                    grid[x+1][y] = 2;
                    q.push({x+1,y});
                }
                //left
                if(y-1 >= 0 && grid[x][y-1] == 1){
                    grid[x][y-1] = 2;
                    q.push({x,y-1});
                }
                //right
                if(y+1 <grid[0].size() && grid[x][y+1] == 1){
                    grid[x][y+1] = 2;
                    q.push({x,y+1});
                }
            }
        }
        return (total == 0)?time-1:-1;
    }
};