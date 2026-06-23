class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        stack<int> st;
        for(int i = nums2.size()-1 ; i>=0; i--){
            if(st.empty()) ans.push_back(-1);
            else if(st.top() > nums2[i]) ans.push_back(st.top());
            else{
                while(!st.empty() && st.top() <= nums2[i]) st.pop();
                if(st.empty()) ans.push_back(-1);
                else ans.push_back(st.top());
            }
            st.push(nums2[i]);
        }
        unordered_map<int,int> mp;
        for(int i = 0 ; i<nums2.size();i++){
            mp[nums2[i]] = ans[nums2.size()-1-i];
        }
        vector<int> res;
        for(auto x: nums1) res.push_back(mp[x]);
        return res;
    }
};