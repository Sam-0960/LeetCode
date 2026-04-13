class Solution {
public:
    int atmost(vector<int>& nums, int k){
        int cnt = 0;
        int res = 0;
        int l = 0 ,r =0;
        while(r<nums.size()){
            if(nums[r] % 2 == 1) cnt++;
            while(cnt > k){
                if(nums[l]%2 == 1) cnt--;
                l++;
            }
            res += r - l +1;
            r++;
        }
        return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums,k-1);
    }
};