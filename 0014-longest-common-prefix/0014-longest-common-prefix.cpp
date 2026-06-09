class Solution {
public:
    static bool comp(string& a, string& b){
        return a.size() < b.size();
    }
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        sort(strs.begin(),strs.end(), comp);
        ans.append(strs[0]);
        
        for(int i = 0 ; i<ans.size() ; i++){
            for(int j = 0; j<strs.size() ;j++){
                if(strs[j][i] != ans[i])
                    return ans.substr(0,i);
            }
        }
        return ans;
    }   
};