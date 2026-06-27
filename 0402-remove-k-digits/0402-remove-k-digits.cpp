class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        stack<int> st;
        while(num.size()>1 && num.front() == '0') num.erase(0,1);
        for(int i=0 ; i<num.size(); i++){
            while(!st.empty() && k>0 && (st.top()-'0') > (num[i]-'0')){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(!st.empty() && k>0  ){
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        while(ans.size()>1 && ans.front() == '0') ans.erase(0,1);
        return ans;
    }
};