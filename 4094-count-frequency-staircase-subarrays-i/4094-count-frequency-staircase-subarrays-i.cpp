class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;vector<int> rank(1e5+1,0); vector<int> freq(1e5+1,0);
        for(int i=0; i<n; i++){
            int j = i;
            int k =0;
            for(; j<n; j++){
                if(!rank[nums[j]]) rank[nums[j]] = ++k;
                freq[nums[j]]++;
                if(freq[nums[j]] > rank[nums[j]]) break;
                else if(j-i+1 == k*(k+1)/2) ans++;
            }
            for(int p = i; p<= min(j,n-1); p++) freq[nums[p]] = rank[nums[p]] = 0;
        }
        return ans;
    }
};