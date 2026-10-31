class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(1e5+1,0); vector<int> rank(1e5+1,0);
        int ans = 0;
        for(int l = 0; l<n ; l++){
            int maxi = 0;int k = 0;
            for(int r= l; r<n; r++){
                maxi = max(maxi,nums[r]);
                if(!rank[nums[r]]) rank[nums[r]] = ++k;
                freq[nums[r]]++;
                if(freq[nums[r]] > rank[nums[r]]){
                    break;
                }else if(r-l+1 == k*(k+1)/2){
                    ans++;
                }
            }
            //clean up freq and rank
            for(int i =0; i<=maxi; i++){
                if(freq[i] != 0){
                    freq[i] = rank[i] = 0;
                }
            }
        }
        return ans;
    }
};