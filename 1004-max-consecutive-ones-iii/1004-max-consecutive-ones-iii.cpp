class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0;
        int zero_count = 0;
        int maxlen = 0;
        while( l<= r && r < nums.size()){
            if(nums[r] == 0){
                if(zero_count < k){
                    zero_count++;
                }else{
                    while(nums[l] == 1) l++;
                    l++;
                }
            }
            maxlen = max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};