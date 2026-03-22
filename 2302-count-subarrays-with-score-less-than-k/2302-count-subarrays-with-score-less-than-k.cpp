class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long score = 0;
        long long count = 0;
        int l =0 , r= 0;
        long long sum = 0;
        while( l <= r && r < nums.size()){
            sum += nums[r];
            score = sum * (r-l+1);
            while(score >= k){
                sum -= nums[l];
                l++;
                score = sum*(r-l+1);
            }
            count += r - l + 1;
            r++;
        }
        return count;
    }
};