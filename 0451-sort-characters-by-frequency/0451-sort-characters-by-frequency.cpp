class Solution {
public:
    static bool comp(pair<char,int>& a, pair<char,int>& b){
        return a.second > b.second;
    }
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto x: s) mp[x]++;
        vector<pair<char,int>> v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),comp);
        string ans ="";
        for(auto x:v){
            for(int i=0; i<x.second ; ++i) ans.push_back(x.first);
        }
        return ans;
    }
};