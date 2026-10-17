class Solution {
public:
    int f(vector<int>& nums, int start, int end){
        pair<int,int> dp;
        dp.first = nums[start];
        dp.second = max(nums[start],nums[start+1]);
        for(int i = start+2; i<=end; i++){
            int v =  dp.second;
            dp.second = max(dp.first+nums[i],dp.second);
            dp.first = v;
        }
        return dp.second;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if( n == 1) return nums[0];
        if( n == 2) return max(nums[0],nums[1]);
        return max(f(nums,0,n-2) , f(nums,1,n-1));
    }
};