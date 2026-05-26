class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxlen = 0;
        unordered_set<int> st(nums.begin(),nums.end());
        for(auto x:st){
            if(st.find(x-1) == st.end()){
                int curr=0;
                int el = x;
                int counter = 0;
                while(st.find(el+counter) != st.end()){
                    curr++;
                    counter++;
                }
                maxlen = max(maxlen,curr);
            }
        }
        return maxlen;
    }
};