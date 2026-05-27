class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l =0,r = 0;
        int maxlen = 0;
        unordered_map<char,int>mp;

        while( l<=r && r<s.size()){
            if(mp.find(s[r]) == mp.end()){
                mp[s[r]]++;
                maxlen = max(maxlen , r-l+1);    
            }else{
                while(mp.find(s[r]) != mp.end()){
                    mp.erase(s[l]);
                    l++;
                }
                mp[s[r]]++;
            }
            r++;
        }
        return maxlen;
    }
};