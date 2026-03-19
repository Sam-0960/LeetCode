class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int maxlen = 0;
        for(auto x: nums){
            int count = 0;
            if(st.find(x-1) == st.end()){
                int el =x;
                while(st.find(el) != st.end()){          
                    count++;
                    el += 1;
                }
                maxlen = max(count,maxlen);
            }
        }
        return maxlen;
    }
};