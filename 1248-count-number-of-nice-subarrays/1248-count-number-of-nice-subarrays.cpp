class Solution {
public:
    int atmost(vector<int>& nums, int k){
        int res = 0 ;
        int l = 0 , r = 0;
        int cnt = 0;
        while(r<nums.size()){
            if(nums[r] == 1) cnt++;
            while(cnt > k){
                if(nums[l] == 1) cnt--;
                l++;
            }
            res += r-l+1;
            r++;
        }
        return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i = 0;i <nums.size(); i++){
            if(nums[i]%2 == 0) nums[i] = 0;
            else nums[i] = 1;
        }
        return atmost(nums,k) - atmost(nums,k-1);
    }
};