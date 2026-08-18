class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<long long,int> mp;
        mp[0] = -1;long long sum = 0;
        for(auto i = 0; i<nums.size();i++){
            sum = (sum+nums[i])%k;
            if(mp.find(sum) != mp.end()){
                if(i-mp[sum] >= 2) return true;
                continue;
            }
            mp[sum] = i;
        }
        return false;
    }
};