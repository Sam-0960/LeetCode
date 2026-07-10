class Solution {
public:
    int res = 0;
        void func(int index, vector<int>& nums, int target, int eval){
            if(index == nums.size()){
                if(eval == target) res++;
                return;
            }
            func(index+1,nums,target, eval + nums[index]);
            func(index+1, nums,target,eval - nums[index]);
            return;
        }
    int findTargetSumWays(vector<int>& nums, int target) {
        func(0,nums,target,0);
        return res;
    }   
};