class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int k = nums.size();
        int target = (int)accumulate(nums.begin(),nums.end(),0LL) ;
        if(target%2) return false;
        target /= 2;
        vector<vector<int>> dp(k+1,vector<int>(target+1,0));
        int n = dp.size();
        for(int i=1; i<n; i++){
            for(int j=1; j<target+1 ; j++){
                dp[i][j] = dp[i-1][j];
                if(j-nums[i-1] >= 0 && (dp[i][j] < (nums[i-1]+dp[ i-1 ][ j-nums[i-1] ]) )  ){
                    dp[i][j] = nums[i-1] + dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n-1][target] == target;
    }
};