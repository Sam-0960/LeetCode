class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = nums[0];
        int curr = 0;
        for(int i=0 ;i<nums.size(); i++){
            curr += nums[i];
            maxsum = max(maxsum, curr);
            if(curr < 0) curr = 0;   
        }
        return maxsum;
    }
};