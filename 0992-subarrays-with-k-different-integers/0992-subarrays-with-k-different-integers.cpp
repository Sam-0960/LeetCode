class Solution {
public:
    int atmost(vector<int>& nums,int k){
        if(k <= 0) return 0;
        unordered_map<int,int> mp;
        int l = 0, r = 0;
        int ans= 0;
        while( r< nums.size()){
            mp[nums[r]]++;
            while(mp.size() > k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
            ans += (r-l+1);
            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums,k-1);
    }
};