class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans;
        stack<pair<int,int>> st;
        for(int i = temperatures.size()-1 ; i>=0; i--){
            int el = temperatures[i];
            if(st.empty()) ans.push_back(0);
            else if(st.top().first > el ) ans.push_back(st.top().second - i);
            else{
                while(!st.empty() && st.top().first <= el){
                    st.pop();
                }
                if(st.empty()) ans.push_back(0);
                else ans.push_back(st.top().second - i);
            }
            st.push(make_pair(el,i));
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};