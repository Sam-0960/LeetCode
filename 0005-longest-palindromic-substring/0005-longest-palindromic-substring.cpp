class Solution {
public:
    pair<int,int> checkPal(string s, int l , int r){
        while(l>=0 && r < s.size() && s[l] == s[r]){
            l--; 
            r++;
        }
        return {l+1,r-l-1};
    }

    string longestPalindrome(string s) {
        int maxlen = 0;
        int start = 0;
        for(int i=0 ; i<s.size(); i++){
            auto [s1,l1] = checkPal(s,i,i);
            auto [s2,l2] = checkPal(s,i,i+1);
            if (l1 > maxlen) { maxlen = l1; start = s1; }
            if (l2 > maxlen) { maxlen = l2; start = s2; }
        }
        return s.substr(start,maxlen);
    }
};