class Solution {
public:
    int func(string s, int k, char x){
        int count = 0;
        int l = 0 ; int r = 0;
        int maxlen = 0;
        while(r<s.size()){
            if(s[r] != x) count++;
            while(count > k){
                if(s[l] != x) count--;
                l++;
            }
            maxlen = max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
    int characterReplacement(string s, int k) {
        int maxlen = 0;
        for(int i = 0 ; i<26; i++){
            maxlen = max(maxlen, func(s,k,(char)('A'+i)));
        }
        return maxlen;
    }
};