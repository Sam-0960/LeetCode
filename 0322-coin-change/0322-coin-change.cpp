class Solution {
public:
    int func(int i, int rem , vector<int>& coins,vector<vector<int>>& dp){
        if(i >= coins.size() || rem < 0) return 1e6;
        if(rem == 0) return 0;
        if(dp[i][rem] != INT_MAX) return dp[i][rem];

        //pick
        int pick = 1 + func(i+1,rem-coins[i],coins,dp);
        //pick and repeat
        int repeat = 1+func(i,rem-coins[i],coins,dp);
        //skip
        int skip = func(i+1,rem,coins,dp);

        dp[i][rem] = min(pick, min(repeat,skip));
        return dp[i][rem];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,INT_MAX));
        int ans = func(0,amount,coins,dp);
        return (ans >= 1e6)? -1: ans;
    }
};