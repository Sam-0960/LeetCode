class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(auto x: t) mp[x]++;
        int l = 0 ; int r = 0;
        int minlen = INT_MAX;
        int start = -1;
        int k = mp.size();
        int cnt = 0;
        while(r<s.size()){
            mp[s[r]]--;
            if(mp[s[r]] == 0) cnt++;
            while(cnt == k){
                int len = r-l+1;
                if(len < minlen){
                    start = l;
                    minlen = len;
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }
        return (start == -1)? "":s.substr(start,minlen);
    }
};