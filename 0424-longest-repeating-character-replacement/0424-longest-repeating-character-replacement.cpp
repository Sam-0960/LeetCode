class Solution {
public:
    int maxletter(string s,int k, char x){
        int count = 0;
        int l=0,r=0;
        int maxlen= 0;
        while(l<=r && r<s.length()){
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
        unordered_map<char,int> v;
        for(auto x: s) v[x]++;
        int res = 0;
        for(auto it:v){
            res = max(res,maxletter(s,k,it.first));
        }
        return res;
    }
};