class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> eff(n,vector<int>(m,INT_MAX));
        vector<pair<int,int>>directions = {{1,0},{0,1},{-1,0},{0,-1}};
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        pq.push({0,0,0});
        eff[0][0] = 0;
        while(!pq.empty()){
            auto [effort,x,y] = pq.top();pq.pop();
            if(x == n-1 && y == m-1) return effort;
            for(auto [dx,dy] : directions ){
                if(x+dx >= n || x+dx < 0 || y+dy >= m ||y+dy < 0)continue;
                int weight = abs(heights[x+dx][y+dy] - heights[x][y]);
                int maxeff = max(weight,effort);
                if(eff[x+dx][y+dy] > maxeff){
                    eff[x+dx][y+dy] = maxeff;
                    pq.push({maxeff,x+dx,y+dy});
                }
            }
        }
        return (eff[n-1][m-1] == INT_MAX)? -1: eff[n-1][m-1];
    }
};