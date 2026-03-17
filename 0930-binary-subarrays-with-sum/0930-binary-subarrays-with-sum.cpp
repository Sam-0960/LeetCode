class Solution {
public:
    long long atmost(vector<int>& nums, int goal){
        if (goal < 0) return 0; // dont forget this edge case
        int l=0,r=0;
        int count = 0;
        long long res = 0;
        while(r<nums.size()){
            if(nums[r] == 1){
                count++;
            }

            while(count > goal){
                if(nums[l] == 1) count--;
                l++;
            }
            res += r-l+1;
            r++;
        }
        return res;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return (int)(atmost(nums,goal) - atmost(nums,goal-1));
    }
};