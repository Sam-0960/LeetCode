class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long count = 0;
        int l=0,r=0;
        long long sum = 0;
        while(l<=r && r<nums.size()){
            sum += nums[r];
            
            while(sum*(r-l+1) >= k){
                sum -= nums[l];
                l++;
            }
            count += (r-l+1);
            r++;
        }
        return count;
    }
};