class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<long long,int> mp;mp[0] = 1;
        int ans = 0;long long sum = 0;
        for(auto x:nums){
            sum += x;
            if(mp.find(sum-goal) != mp.end()) ans += mp[sum-goal];
            mp[sum]++;
        }
        return ans;
    }
};