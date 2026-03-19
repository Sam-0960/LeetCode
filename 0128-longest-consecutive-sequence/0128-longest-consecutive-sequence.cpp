class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(auto x: nums) st.insert(x);
        int maxlen = 0;
        for(auto x: nums){   
            if(st.find(x-1) == st.end()){
                int el =x;
                int count = 0;
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