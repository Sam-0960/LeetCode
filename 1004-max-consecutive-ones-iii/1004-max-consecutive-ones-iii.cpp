class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen = INT_MIN;
        int l =0, r = 0;
        int count = 0;
        while(l <= r && r< nums.size()){
            if(nums[r] == 0) count++;
            while(count > k){
                if(nums[l] == 0)count--;
                l++;
            }
            maxlen = max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};