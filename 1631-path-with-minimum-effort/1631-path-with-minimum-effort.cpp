class Solution {
public:
    vector<pair<int,int>> dir = { {1,0},{-1,0} , {0,1},{0,-1} };
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r = heights.size(); int c = heights[0].size();
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        pq.push({0,0,0});
        vector<vector<int>> ans(r,vector<int>(c,INT_MAX));
        ans[0][0] = 0;
        while(!pq.empty()){
            auto [diff,x,y] = pq.top(); pq.pop();
            if(ans[x][y] < diff) continue;
            if( x == r-1 && y == c-1) return ans[x][y];
            for(auto [dx,dy] : dir){
                if( x+dx >= r || x+dx < 0 || y+dy >= c || y+dy < 0 ) continue;
                int d = abs(heights[x][y] - heights[x+dx][y+dy]);
                int el = max(d,diff);
                if(ans[x+dx][y+dy] > el){
                    ans[x+dx][y+dy] = el;            
                    pq.push({ans[x+dx][y+dy],x+dx,y+dy});
                }
            }
        }
        return -1;
    }
};