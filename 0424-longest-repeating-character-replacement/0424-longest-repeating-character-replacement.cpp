class Solution {
public:
    int atmost(string s , int k , char x){
        int l = 0 ,r = 0;
        int maxlen = 0;
        int count = 0;
        while(r<s.size()){
            if(s[r] != x) count++;

            while(count > k){
                if(s[l] != x) count--;
                l++;
            }
            maxlen = max(maxlen , r-l+1);
            r++;
        }
        return maxlen;
    }

    int characterReplacement(string s, int k) {
        int maxlen = 0;
        for(int i=0; i<26;i++){
            maxlen = max(maxlen , atmost(s,k,(char)(i+65)));
        }
        return maxlen;
    }
};