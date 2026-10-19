class Solution {
public:
    vector<pair<int,int>> dir = {{-1,-1},{-1,0},{-1,1}};
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int row = 1; row<n; row++){
            for(int col = 0; col <n ; col++){
                int mini =INT_MAX;
                for(auto [dx,dy] : dir){
                    if(row+dx >= n || row+dx <0 || col+dy >= n || col+dy < 0) continue;
                    mini = min(mini,matrix[row+dx][col+dy]);
                }
                matrix[row][col] += mini;
            }
        }
        int ans = INT_MAX;
        for(int i=0; i<n ; i++) ans = min(ans,matrix[n-1][i]);
        return ans;
    }
};