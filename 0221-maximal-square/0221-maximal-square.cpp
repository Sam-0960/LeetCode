class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(); int n = matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
        for(int i=0; i<m ; i++){
            for(int j =0 ; j<n ; j++){
                dp[i][j] = (matrix[i][j] - '0');
            }
        }
        for(int i=1; i<m ; i++){
            for(int j =1 ; j<n ; j++){
                if(dp[i][j])
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) + 1;
            }
        }
        int ans = 0;
        for(auto& x: dp)
            for(auto &y : x)
                ans = max(y,ans);
        return ans*ans;
    }
};