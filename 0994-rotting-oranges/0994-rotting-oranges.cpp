class Solution {
public:
    vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(); int n = grid[0].size();
        queue<pair<int,int>> q;
        int time = 0;
        int total = 0;
        for(int i=0 ; i<grid.size(); i++){
            for(int j=0 ; j<grid[i].size(); j++){
                if(grid[i][j] == 2) {
                    q.push({i,j});
                }
                if(grid[i][j] != 0) total++;
            }
        }
        if(total == 0) return 0;
        if(q.empty()) return -1;
        while(!q.empty()){
            int k = q.size();
            total-= k;
            for(int i = 0;i<k ; i++){
                auto [x,y] = q.front();q.pop();
                for(auto [dx,dy] : dir){
                    if(x+dx < 0 || x+dx >= m || y+dy < 0 || y+dy >=n || grid[x+dx][y+dy] == 2 || grid[x+dx][y+dy] == 0) continue;
                    if(grid[x+dx][y+dy] == 1){
                        grid[x+dx][y+dy] = 2;
                        q.push({x+dx,y+dy});
                    }
                }
            }
            time++;
        }
        if(total != 0) return -1;
        return time-1;
    }
};