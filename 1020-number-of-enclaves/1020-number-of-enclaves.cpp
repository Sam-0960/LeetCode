class Solution {
public:
    vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
    void dfs(int x, int y, vector<vector<int>>& grid){
        if(x >= grid.size() || y >= grid[0].size() || x<0 || y < 0 || grid[x][y] == 0) return;
        grid[x][y] = 0;
        dfs(x+1,y,grid);dfs(x-1,y,grid);dfs(x,y+1,grid);dfs(x,y-1,grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(); int n = grid[0].size();
        for(int i=0;i<n;i++){
                dfs(0,i,grid);
                dfs(m-1,i,grid);
        }
        for(int i=1;i<m;i++){ 
                dfs(i,0,grid);
                dfs(i,n-1,grid);
        }
        int ans = 0;
        for(int i=1; i<= m-1; i++)
            for(int j=1; j<=n-1;j++)
                if(grid[i][j]) ans++;

        return ans;
    }
};