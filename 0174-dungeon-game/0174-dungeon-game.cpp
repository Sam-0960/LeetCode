class Solution {
public:
    bool isCheck(int row,int col,int m , int n){
        return (row < 0 || row >= m || col < 0 || col >= n)? false: true;
    }
    vector<pair<int,int>> dir = {{1,0},{0,1}};
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(); int n = dungeon[0].size();
        dungeon[m-1][n-1] = (dungeon[m-1][n-1] < 0)? abs(dungeon[m-1][n-1]) + 1 : 1;
        for(int i=m-1; i>= 0 ; i--){
            for(int j=n-1; j>=0 ; j--){
                int insert = INT_MAX;
                for(auto [dx,dy] : dir){
                    if(isCheck(i+dx,j+dy,m,n)){
                        insert = min(insert,(dungeon[i+dx][j+dy]-dungeon[i][j]));
                    }
                }
                if(insert != INT_MAX) dungeon[i][j] = max(1,insert);
            }
        }
        return dungeon[0][0];
    }
};