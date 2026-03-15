class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int count = 0;int sum = 0;
        for(int i=0; i<nums.size();i++){
            sum += nums[i];

            if(mp.find(sum-goal) != mp.end()) count += mp[sum-goal];
            mp[sum]++;
        }
        return count;
    }
};