class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> indices;
        int l = 0 , r = 0;
        int cnt = p.size();
        unordered_map<char,int> mp;
        for(auto x: p) mp[x]++;
        while(r<s.size()){
            mp[s[r]]--;
            if(mp[s[r]] >= 0) cnt--;
            while(cnt == 0){
                if(r-l+1 == p.size()) indices.push_back(l);
                mp[s[l]]++;
                if(mp[s[l]] > 0) cnt++;
                l++;
            }
            r++;
        }
        return indices;
    }
};