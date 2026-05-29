class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int l =0 , r = 0;
        unordered_map<int,int> mp;
        long long maxsum = 0 , sum = 0;
        while(l <= r && r<nums.size()){
            mp[nums[r]]++;
            sum += nums[r];
            while( r - l + 1> k || mp[nums[r]] >1){
                mp[nums[l]]--;
                sum -= nums[l];
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
            if(r-l+1 == k)
                maxsum = max(maxsum, sum);
            r++;
        }
        return maxsum;
    }
};