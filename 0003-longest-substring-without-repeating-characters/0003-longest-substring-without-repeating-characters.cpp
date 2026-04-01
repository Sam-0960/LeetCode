class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int l = 0 , r = 0;
        int maxlen = 0;
        while( r<s.size()){
            if(mp.find(s[r]) != mp.end()){
                l = max(mp[s[r]]+1, l);
            }    
            maxlen = max(maxlen, r-l+1);
            mp[s[r]]=r;
            r++;
        }
        return maxlen;
    }
};