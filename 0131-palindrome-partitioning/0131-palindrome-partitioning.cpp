class Solution {
public:
    vector<vector<string>> ans;
    void func(int index,vector<string>& v, string& s){
        if(index == s.size()){
            ans.push_back(v);
            return;
        }
        for(int i = index ; i<s.size(); i++){
            if(check(index, i, s)){
                string k = s.substr(index,i-index+1);
                v.push_back(k);
                func(i+1,v,s);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> v;
        func(0,v,s);
        return ans;
    }   
    bool check(int start, int end, string& s){
        while(start <= end){
            if(s[start++] != s[end--]) return false;
        }
        return true;
    }
};