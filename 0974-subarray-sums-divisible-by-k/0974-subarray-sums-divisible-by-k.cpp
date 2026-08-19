class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0] = 1; int ans = 0;int sum = 0;
        for(auto x:nums){
            if(x<0) x = (x%k + k)%k;       
            sum = (sum+x)%k;
            if(mp.find(sum) !=mp.end()) ans += mp[sum];
            mp[(sum%k+k)%k]++;
        }
        return ans;
    }
};