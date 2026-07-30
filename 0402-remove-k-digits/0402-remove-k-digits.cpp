class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() == 0 ||  k == num.size())
            return "0";
        if (k == 0)
            return num;
        stack<char> st;
        int removed = 0;
        for (int i = 0; i < num.size(); i++) {
            while (!st.empty() && st.top() > num[i] && removed < k) {
                st.pop();
                removed++;
            }
            st.push(num[i]);
        }
        while(removed < k){
            st.pop();
            removed++;
        }
        string ans="";
        if(st.empty()) return ans;
        while(!st.empty()){
            char ch = st.top(); st.pop();
            ans.push_back(ch);
        }
        reverse(ans.begin(),ans.end());
        int i=0;
        while(!ans.empty() && ans[i] == '0') i++;
        ans = ans.substr(i);
        return ans.empty() ? "0" : ans;
    }
};