class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mp;
        mp[0] = 1;
        int sum = 0;
        int count = 0;
        for(int i=0 ; i<nums.size(); i++){
            sum += nums[i];
            int rem = sum - goal;
            if(mp.find(rem) != mp.end()) count+= mp[rem];
            mp[sum]++;
        }
        return count;
    }
};