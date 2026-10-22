class Solution {
public:
    vector<pair<int,int>> dir = {{-1,0},{0,-1}};
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(); int n = grid[0].size();
        for(int x = 0; x < m; x++){
            for(int y = 0; y <n; y++){
                int mini = INT_MAX;
                for(auto [dx,dy]: dir){
                    if(x+dx < 0 || x+dx >=m || y+dy < 0 || y+dy >= n) continue;
                    mini = min(mini,grid[x+dx][y+dy]);
                }
                if(mini < INT_MAX) grid[x][y] += mini;
            }
        }
        return grid[m-1][n-1];
    }
};