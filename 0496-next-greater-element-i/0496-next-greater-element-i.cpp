class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;vector<int> v;
        int n = nums2.size();
        for(int i = n-1 ; i>= 0 ; i--){
            int el = nums2[i];
            while(!st.empty() && st.top()<= el) st.pop();
            if(st.empty()) v.push_back(-1);
            else v.push_back(st.top());
            st.push(el);
        }
        unordered_map<int,int> mp;
        for(int i = 0 ; i<nums2.size(); i++) mp[nums2[i]] = v[n-i-1];
        vector<int> ans;
        for(auto i = 0 ; i<nums1.size() ;i++){
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};