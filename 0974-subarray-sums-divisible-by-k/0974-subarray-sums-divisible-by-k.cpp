class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int,int> mp;
        int sum = 0;
        mp[0] = 1;
        for(int i = 0 ; i<nums.size();++i){
            sum += nums[i];
            int rem = sum % k;
            if(rem < 0 ) rem  += k;
            ans += mp[rem];
            mp[rem]++;
        }
        return ans;
    }
};