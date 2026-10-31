class Solution {
public:
    int ans = 0;
    void func(int index,int sum, vector<int>& nums, int target){
        if(index > nums.size()) return;
        if(index == nums.size()){
            if(sum == target) ans++;
            return;
        }
        //pick the index as pos
        func(index+1,sum+nums[index],nums,target);
        //pick the index as neg
        func(index+1,sum-nums[index],nums,target);

        return;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        func(0,0,nums,target);
        return ans;
    }
};