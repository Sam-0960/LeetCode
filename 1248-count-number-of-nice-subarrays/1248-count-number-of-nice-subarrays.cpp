class Solution {
public:
    int atmost(vector<int>& nums, int k){
        int l=0,r=0;
        int odd_count = 0;
        int res = 0;
        while(l<=r && r<nums.size()){
            if(nums[r]%2 == 1){
                odd_count++;
            }

            while(odd_count > k){
                if(nums[l]%2 == 1) odd_count--; 
                l++;
            }
            res += (r-l+1);
            r++;
        }
        return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums,k-1);
    }
};