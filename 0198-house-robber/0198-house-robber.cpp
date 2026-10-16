class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        pair<int,int> dp = {nums[0],max(nums[0],nums[1])};
        for(int i = 2;i<nums.size();i++){
            int prev2 = dp.first;
            int prev1 = dp.second;
            dp.first = dp.second;
            dp.second = max(nums[i]+prev2,prev1);
        }
        return dp.second;
    }
};