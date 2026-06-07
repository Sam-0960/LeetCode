class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int hash[100000] = {0};
        hash[0] = 1;
        int cnt = 0;
        int pref[nums.size()]; 

        for(int i = 0 ; i<nums.size(); i++){
            pref[i] = (i == 0)? nums[0] : pref[i-1] + nums[i];
            int rem = pref[i]%k;
            if(rem < 0) rem += k;
            cnt += hash[rem];
            hash[rem]++;
        }   
        return cnt;
    }
};