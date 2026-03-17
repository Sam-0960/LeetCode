class Solution {
public:
    int maxPower(string s) {
        int maxlen = 0;
        int l = 0; 
        int r = 0;
        while(l<=r && r<s.length()){
            if(s[r] != s[l]) l = r;
            maxlen = max(maxlen, r-l+1);
            r++;
        }
        return maxlen;
    }
};