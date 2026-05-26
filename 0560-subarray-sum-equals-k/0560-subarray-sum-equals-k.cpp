class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int sum = 0;
        int count = 0;
        for(auto x: nums){
            sum += x;
            if(mp.find(sum-k) != mp.end()) count+=mp[sum-k];
            mp[sum]++;
        }
        return count;
    }
};