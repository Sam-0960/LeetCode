class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n);
        vector<int> suff(n);

        pref[0] = 0;
        for(int i=1 ; i<n;i++) pref[i] = pref[i-1]+nums[i-1];
        suff[n-1] = 0;
        for(int i=n-2 ; i>=0 ;i--) suff[i] = suff[i+1]+nums[i+1];

        for(int i=0 ; i<nums.size(); i++){
            if(pref[i] == suff[i] ) return i;
        }
        return -1;
    }
};