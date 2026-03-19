class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int l=0, r=0;
        int maxlen = 0;
        while(l<=r  && r<s.length()){
            while(mp.find(s[r])!= mp.end()){
                mp.erase(s[l++]);
            }
            mp[s[r]] = r;
            maxlen = max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }
};