class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}};
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        pq.push({1,0,0});
        grid[0][0] =1;
        while(!pq.empty()){
            auto [dis,x,y] = pq.top();pq.pop();
            if(x == n-1 && y == n-1) return dis;
            for(auto [dx,dy] : directions){
                if(x+dx <0 || x+dx >=n || y+dy < 0 || y+dy >= n || grid[x+dx][y+dy] == 1) continue;
                if(grid[x+dx][y+dy] == 0){
                    pq.push({dis+1,x+dx,y+dy});
                    grid[x+dx][y+dy] = 1;
                }
            }
        }
        return -1;
    }
};