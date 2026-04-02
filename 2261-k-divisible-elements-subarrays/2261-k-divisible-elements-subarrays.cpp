class Solution {
public:
    struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        size_t hash = 0;
        for (int x : v) {
            hash ^= hash * 31 + x;
        }
        return hash;
        }
    };
    int countDistinct(vector<int>& nums, int k, int p) {
        unordered_set<vector<int>,VectorHash> st;
        for(int i =0 ; i<nums.size();i++){
            int cnt = 0;
            for(int j = i;j<nums.size(); j++){
                    if(nums[j]%p == 0)cnt++;
                    if(cnt > k) break;
                    vector<int> v(nums.begin()+i,nums.begin()+j+1);
                    st.insert(v);                
            }
        }
        return st.size();
    }
};