class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(triangle[n-1].size());
        for(int i=0; i<dp.size();i++) dp[i] = triangle[n-1][i];
        for(int i = n-1; i>0 ; i--){
            int size = triangle[i].size();
            for(int j = 0; j<size-1; j++){
                dp[j] = triangle[i-1][j] + min(dp[j],dp[j+1]);
            }
        }
        return dp[0];
    }
};