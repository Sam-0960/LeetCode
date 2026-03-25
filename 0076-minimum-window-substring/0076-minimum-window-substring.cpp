class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(auto x : t) mp[x]++;

        int l = 0 ; int r = 0;
        int cnt = 0;
        int n = mp.size();
        int minlen = INT_MAX ;
        int sindex = -1;
        while( r < s.size()){
            mp[s[r]]--;
            if(mp[s[r]] == 0) cnt++;

            while(cnt == n){
                mp[s[l]]++;
                if(mp[s[l]] > 0) cnt--;
                if(r-l+1 < minlen){
                    minlen = r-l+1;
                    sindex = l;
                }
                l++;
            }
            r++;
        }
        return (sindex == -1) ? "" : s.substr(sindex, minlen);
    }
};