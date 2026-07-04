class Solution {
public:
    vector<string> ans;
    void f(int n , int open , int closed, string s){
        if(s.size() == 2*n){
            ans.push_back(s);
            return;
        }
        if( open < n){
            s.push_back('(');
            f(n,open+1,closed,s);
            s.pop_back();        
        }
        if(open > closed){
            s.push_back(')');
            f(n,open,closed+1,s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s;
        f(n,0,0,s);
        return ans;
    }
};