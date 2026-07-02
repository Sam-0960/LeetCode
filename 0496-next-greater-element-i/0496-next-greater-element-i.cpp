class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;stack<int> st;
        for(int i = nums2.size()-1 ; i>= 0 ; i--){
            int el = nums2[i];
            while(!st.empty() && st.top() < el) st.pop();
            if(st.empty()) v.push_back(-1);
            else v.push_back(st.top());
            st.push(el);
        }
        unordered_map<int,int> mp;
        for(auto i = 0 ; i<nums2.size() ; i++) mp[nums2[i]] = v[nums2.size()-i-1];
        vector<int> res;
        for(auto i = 0 ; i<nums1.size(); i++){
            res.push_back(mp[nums1[i]]);
        }   
        return res;
    }
};