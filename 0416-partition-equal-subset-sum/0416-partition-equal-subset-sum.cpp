class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(),nums.end(),0LL);
        if(total%2) return false;
        int n = nums.size();
        total = total/2;
        vector<vector<bool>> dp(n+1,vector<bool>(total+1,false));
        for(int i = 1; i <= n ; i++){
            for(int j = 0; j <= total; j++){
                dp[i][j] = dp[i-1][j];
                if( nums[i-1] == j) dp[i][j] = true;
                else if(j> nums[i-1] ){
                    if(dp[i-1][j-nums[i-1]]) dp[i][j] = true;
                } 
            }
        }
        return dp[n][total];
    }
};