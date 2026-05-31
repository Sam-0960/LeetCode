class Solution {
public:
    long long atmost(vector<int>& nums, int el, int k){
        long long res = 0;
        int l = 0 , r = 0;
        long long count = 0;
        while( r<nums.size()){
            if(nums[r] == el) count++;
            while(count > k){
                if(nums[l] == el) count--;
                l++;
            }
            res += r-l+1;
            r++;
        }
        return res;
    }
    long long countSubarrays(vector<int>& nums, int k) {
        int res = 0;
        int l = 0 , r =0;
        int count = 0;
        int el = *max_element(nums.begin(),nums.end());
        int total_occurences_el = 0;
        for(auto x: nums) if(x == el) total_occurences_el++;
        
        return atmost(nums,el,total_occurences_el) - atmost(nums,el,k-1);
    }
};