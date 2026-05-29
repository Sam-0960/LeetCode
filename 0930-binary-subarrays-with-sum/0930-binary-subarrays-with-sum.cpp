class Solution {
public:
    int atmost(vector<int>& nums,int k){
        if(k < 0) return 0;
        int l = 0 , r = 0;
        int res = 0;
        int count = 0;
        while (r < nums.size()){
            if(nums[r] == 1) count++;
            while(count > k){
                if(nums[l] == 1) count--;
                l++;
            }
            res += r-l+1;
            r++;
        }
        return res;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums,goal) - atmost(nums,goal-1);
    }
};