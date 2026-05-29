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
        unordered_set<int>st (s.begin(),s.end());
        int maxlen = 0;
        for(auto x: st){
            maxlen = max(maxlen , atmost(s,k,x));
        }
        return maxlen;
    }
};