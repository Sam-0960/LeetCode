class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        if(nums.size() == 2){
            int sum = 0;
            for(auto x: nums) sum +=x;
            if(sum == 0 || sum == 2) return 0;
            else return 2;
        }
        unordered_map<int,int> mp;
        mp[0] = -1;
        int sum = 0;
        int maxlen = INT_MIN;
        for(auto &it: nums) if(it == 0) it = -1;
        for(auto i=0;i< nums.size();i++){
            sum += nums[i];
            if(mp.find(sum) != mp.end()){
                maxlen = max(maxlen, i-mp[sum]);
                continue;
            }
            mp[sum] = i;
        }
        return (maxlen == INT_MIN)? 0 : maxlen;
    }
};