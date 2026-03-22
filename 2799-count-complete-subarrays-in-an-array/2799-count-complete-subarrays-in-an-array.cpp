class Solution {
public:
    int atmost(vector<int>& nums, int k){
        int l = 0 , r = 0;
        unordered_map<int,int> mp;
        int count = 0;
        while(l<=r && r<nums.size()){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]] == 0) mp.erase(nums[l]);
                l++;
            }
            count += r-l+1;
            r++;
        }
        return count;
    }
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> st;
        for(auto x: nums) st.insert(x);

        return atmost(nums,st.size()) - atmost(nums,st.size()-1);
    }
};