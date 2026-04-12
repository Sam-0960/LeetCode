class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(auto x: t) mp[x]++;
        int l = 0 , r = 0;
        int minlen = INT_MAX;
        int start = -1;
        // move right ptr until all the els in t fit inside my window in s
        // move left ptr to only optimise the window len to minimum
        int n = mp.size();
        int cnt = 0;
        while(r < s.size()){
            mp[s[r]]--;
            if(mp[s[r]] == 0) cnt++;
            while(cnt == n){
                if( r-l+1 < minlen){
                    start = l;
                    minlen = r-l+1;
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }
        return (start == -1)? ""  : s.substr(start,minlen);
    }
};