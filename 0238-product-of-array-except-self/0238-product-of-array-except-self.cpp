class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n);
        vector<int> suff(n);
        vector<int> ans(n);
        
        pref[0] =  nums[0];
        for(int i=1 ; i<nums.size(); i++)   pref[i] = nums[i]*pref[i-1];
        suff[n-1] = nums[n-1];
        for(int i = n-2; i>= 0 ; i--)   suff[i] = nums[i]*suff[i+1];

    
        ans[0] = suff[1];
        ans[n-1] = pref[n-2];
        for(int i=1 ; i <nums.size()-1; i++){
            ans[i] = pref[i-1]* suff[i+1];
        }
        return ans;
    }
};