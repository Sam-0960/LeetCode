class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count = 0;
        int l =0 ,r =0;
        int maxlen = 0;
        while(l <= r && r<nums.size()){
            if(nums[r] != 1){
                count++;
            }
            while( count > k){
                if(nums[l] != 1) count--;
                l++;
            }
            maxlen = max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};