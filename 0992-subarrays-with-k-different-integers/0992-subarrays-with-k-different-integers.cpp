class Solution {
public:
    int atmost(vector<int>& nums, int k){
        int res = 0;
        int l = 0 , r = 0;
        unordered_map<int,int> mp;
        while(r<nums.size()){
            mp[nums[r]]++;
            while(mp.size() > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
            res += r-l+1;
            r++;
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums,k-1);
    }
};