class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n,0);
        pref[0] = nums[0];
        const int mod = 1e9+7;
        for(int i=1; i<n; i++) pref[i] = pref[i-1] + nums[i];
        if(pref[n-1] == 0){
            long long x = n-2;
            x = x*(x+1);
            x =x/2;
            return (int)(x%mod);
        }
        long long ans = 0;
        for(int i=0; i<n-2; i++){
            int left = pref[i];
            int rem = pref[n-1]-pref[i];
            int lb = lower_bound(pref.begin()+i+1,pref.end(),2*left) - pref.begin();
            int rb = upper_bound(pref.begin()+i+1,pref.end(),left+rem/2) - pref.begin();
            int res = rb-lb;
            ans += max(0,res);
        }
        return (int)(ans%mod);
    }
};