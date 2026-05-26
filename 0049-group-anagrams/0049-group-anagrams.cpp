class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mp;
        for(auto x:strs){
            string word = x;
            sort(word.begin(), word.end());
            mp[word].push_back(x); 
        }
        
        vector<vector<string>> ans;
        for(auto x: mp){
            vector<string> push;
            for(auto y:x.second){
                push.push_back(y);
            }
            ans.push_back(push);
        }
        return ans;
    }
};