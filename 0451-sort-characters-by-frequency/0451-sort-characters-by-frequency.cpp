class Solution {
public:
    static bool comp(pair<char,int>&a , pair<char,int> &b){
        return a.second > b.second;
    }
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto x: s) mp[x]++;
        vector<pair<char,int>> v;
        for(auto x: mp) v.push_back({x.first, x.second});
        sort(v.begin(),v.end(), comp);
        string res;
        for(int i = 0 ; i<v.size() ; i++){
            int j = v[i].second;
            for(int k = 0 ; k< j ; k++){
                res.push_back(v[i].first);
            }
        } 
        return res;
    }
};