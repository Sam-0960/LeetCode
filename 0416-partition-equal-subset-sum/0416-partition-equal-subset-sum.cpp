class Solution {
public:
    bool func(vector<int>& nums,vector<vector<int>>& dp, int index, int sum , int target){
        if(index >= nums.size()) return false;
        if(sum > target) return false;
        if(sum == target){
            return true;
        }
        if(dp[index][sum] != -1) return dp[index][sum] >= 1;

        bool pick = func(nums,dp,index+1,sum+nums[index],target);
        if(pick){
            dp[index][sum] = pick;
            return dp[index][sum] >= 1;
        }
        bool dont = func(nums,dp,index+1,sum,target);
        dp[index][sum] = dont;
        return dp[index][sum] >= 1;
    }
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(),nums.end(),0LL);
        if(total%2) return false;
        total = total/2;
        vector<vector<int>> dp(nums.size()+1,vector<int>(total+1,-1));
        return func(nums,dp,0,0,total);
    }
};