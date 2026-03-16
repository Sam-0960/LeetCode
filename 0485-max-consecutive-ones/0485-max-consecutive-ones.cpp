class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l=0,r=0;
        unordered_map<int,int> mp;
        int maxcount = 0;
        int count = 0;
        while(l<=r && r < nums.size()){
            if(nums[r] == 1){
                count++;
            }else{
                l=r+1;
                count = 0;
            }
            r++;
            maxcount = max(maxcount,count);
        }
        return maxcount;
    }
};