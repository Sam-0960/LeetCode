class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0; i<nums.size(); i++){
            if(nums[i] % 2 == 1) nums[i] = 1;
            else nums[i] = 0;
        }
        int res = 0;
        int sum = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        for(auto x: nums){
            sum += x;
            if(mp.find(sum-k) != mp.end()){
                res+= mp[sum-k];
            }
            mp[sum]++;
        }
        return res;
    }
};