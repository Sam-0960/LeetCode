class Solution {
public:
    int beautySum(string s) {
        int res = 0;
        for(int i=0;i<s.size();++i){
            unordered_map<char,int> mp;
            for(int j = i ; j<s.size();++j){
                int maxfreq = 0,minfreq = INT_MAX;
                mp[s[j]]++;
                for(auto x:mp){
                    maxfreq = max(maxfreq, x.second);
                    minfreq = min(minfreq , x.second);
                }
                if(minfreq == INT_MAX) res += 0;
                else
                    res += (maxfreq - minfreq);
            }
        }
        return res;
    }
};