class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q; int total = 0;
        int row = grid.size();int col = grid[0].size();
        for(int i = 0; i<row;i++){
            for(int j =0; j<col; j++){
                if(grid[i][j] == 2) q.push({i,j});
                if(grid[i][j] ==1 || grid[i][j] == 2) total++;
            }
        }
        if(total == 0) return 0;
        if(q.empty()) return -1;
        vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
        int time = 0;
        while(!q.empty()){
            int n = q.size();
            total = total -n;
            for(int i=0; i<n; i++){
                auto [x,y] = q.front(); q.pop();
                for(auto [dx,dy] : dir){
                    if(x+dx >= row || x+dx < 0 || y+dy >= col || y+dy <0 || grid[x+dx][y+dy] != 1)
                        continue;
                    grid[x+dx][y+dy] = 2;
                    q.push({x+dx,y+dy});
                }
            }
            time++;
        }
        if(total != 0) return -1;
        return time-1;
    }
};