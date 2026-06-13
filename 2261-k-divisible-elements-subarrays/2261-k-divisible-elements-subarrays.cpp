class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> st;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int cnt = 0;
            vector<int> cur;

            for(int j=i;j<n;j++){
                cur.push_back(nums[j]);

                if(nums[j] % p == 0)
                    cnt++;

                if(cnt > k)
                    break;

                st.insert(cur);
            }
        }
        
        return st.size();
    }
};