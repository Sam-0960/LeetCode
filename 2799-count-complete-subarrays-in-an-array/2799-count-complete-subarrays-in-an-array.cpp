class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto x: nums) mp[x]++;
        int k = mp.size();
        int l =0 , r = 0;
        int res = 0;
        unordered_map<int,int> x;
        int n = nums.size();
        while(r<nums.size()){
            x[nums[r]]++;
            while(x.size() == k){
                res += (n-r);
                x[nums[l]]--;
                if(x[nums[l]] == 0) x.erase(nums[l]);
                l++;
            }
            r++;
        }
        return res;
    }
};