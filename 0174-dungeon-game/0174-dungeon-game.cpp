class Solution {
public:
    vector<pair<int,int>> dir = { {1,0},{0,1}};
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(); int n = dungeon[0].size();
        dungeon[m-1][n-1] = (dungeon[m-1][n-1] < 0)? abs(dungeon[m-1][n-1]) +1 : 1;
        for(int i = m-1; i>= 0; i--){
            for(int j = n-1 ; j >= 0 ; j--){
                int el = INT_MAX;
                for(auto [dx,dy] : dir){
                    if(i+dx < 0 || i+dx >= m || j +dy < 0 || j+dy >= n) continue;
                    el = min(el, dungeon[i+dx][j+dy] -dungeon[i][j] );
                }
                el = max(1,el);
                if(el != INT_MAX) dungeon[i][j] = el;
            }
        }
        return dungeon[0][0];
    }
};