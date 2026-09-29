class Solution {
public:
    vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};
    void bfs(vector<vector<char>>& grid,int a , int b){
        queue<pair<int,int>> q;
        q.push({a,b});
        grid[a][b] = 0;
        while(!q.empty()){
            auto [x,y] = q.front(); q.pop();
            for(auto [dx,dy] : dir){
                if(x+dx< 0 || x+dx >= grid.size() || y+dy >= grid[0].size() || y+dy < 0 || grid[x+dx][y+dy] == '0') continue;
                grid[x+dx][y+dy] = '0';
                q.push({x+dx,y+dy});
            } 
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans  = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j = 0; j<grid[i].size(); j++)
                if(grid[i][j] == '1'){
                    bfs(grid,i,j);
                    ans++; 
                }
        }
        return ans;
    }
};