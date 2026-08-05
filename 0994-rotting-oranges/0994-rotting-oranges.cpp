class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n = grid.size(); int m = grid[0].size();
        int total = 0;
        for(int i=0; i<n;i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2) q.push({i,j});
                if(grid[i][j] == 2 || grid[i][j] == 1) total++;
            }
        }
        if(total == 0) return 0;
        if(q.empty()) return -1;
        int time = 0;
        while(!q.empty()){
            int k = q.size();
            ++time;
            total -= k;
            for(int i=0; i<k; i++){
                auto [x,y] = q.front();
                q.pop();
                if(x-1>=0 && grid[x-1][y] == 1){
                    grid[x-1][y] = 2;
                    q.push({x-1,y});
                }
                if(x+1<n && grid[x+1][y] == 1){
                    grid[x+1][y] = 2;
                    q.push({x+1,y});
                }
                if(y-1>=0 && grid[x][y-1] == 1){
                    grid[x][y-1] = 2;
                    q.push({x,y-1});
                }
                if(y+1<m && grid[x][y+1] == 1){
                    grid[x][y+1] = 2;
                    q.push({x,y+1});
                }
            }
        }
        return (total == 0)? time-1:-1;
    }
};