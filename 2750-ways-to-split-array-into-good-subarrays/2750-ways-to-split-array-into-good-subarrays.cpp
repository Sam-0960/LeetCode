class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        long long res = 1;
        const int MOD = 1e9 + 7;
        int i = 0; int n = nums.size();
        for( i= 0; i<n ;i++) if(nums[i] == 1) break;
        if(i==n) return 0;
        int l = i;
        int j = n-1;
        for(j = n-1; j>0 ;j--) if(nums[j] == 1) break;
        int m = j;
        while(l <= m){
            int z = 1;
            int i ;
            for( i = l+1; i<=m;i++){
                if(nums[i] == 1) break;
                z++;
            }
            l = i;
            res = (res * z)%MOD;
        }
        return res;
    }
};