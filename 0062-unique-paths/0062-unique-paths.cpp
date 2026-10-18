class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> grid(m,vector<int>(n,0));
        grid[0][0] = 1;
        set<pair<int,int>> st;
        st.insert({0,0});
        while(!st.empty()){
            auto [x,y] = *st.begin(); st.erase({x,y});
            if(x+1 < m){
                grid[x+1][y] += grid[x][y];
                st.insert({x+1,y});
            }
            if(y+1 < n ){
                grid[x][y+1] += grid[x][y];
                st.insert({x,y+1});
            }
        }
        return grid[m-1][n-1];
    }
};