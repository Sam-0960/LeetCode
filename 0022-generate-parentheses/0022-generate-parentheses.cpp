class Solution {
public:
    void func(int open, int close, string& s, vector<string>& ans,int n){
        if(s.size() == 2*n){
            ans.push_back(s);
            return;
        }
        if(open < n){
            s.push_back('(');
            func(open+1,close,s,ans,n);
            s.pop_back();
        }
        if(open > close){
            s.push_back(')');
            func(open,close+1,s,ans,n);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) { 
        vector<string> ans;
        int open = 0; int close = 0;string s;
        func(open,close,s,ans,n);
        return ans;
    }
};