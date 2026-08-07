class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& grid){
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0) return;
        grid[row][col] = 0;
        dfs(row-1,col,grid);dfs(row+1,col,grid);dfs(row,col-1,grid);dfs(row,col+1,grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        for(int i=0; i<m;i++){
            if(grid[0][i] == 1) dfs(0,i,grid);
            if(grid[n-1][i] == 1) dfs(n-1,i,grid);
        }
        for(int i=1; i<n;i++){
            if(grid[i][0] == 1) dfs(i,0,grid);
            if(grid[i][m-1] == 1) dfs(i,m-1,grid);
        }
        int ans = 0;
        for(int i=0 ; i<n; i++){
            for(int j =0 ; j<m ;j++){
                if(grid[i][j] == 1) ans++;
            }
        }
        return ans;
    }
};