class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long,int> mp;
        mp[0] = 1;long long sum = 0; int cnt  = 0;
        for(auto x: nums){
            sum += x;
            if(mp.find(sum - k) != mp.end()) cnt += mp[sum-k];
            mp[sum]++;
        }
        return cnt;
    }
};