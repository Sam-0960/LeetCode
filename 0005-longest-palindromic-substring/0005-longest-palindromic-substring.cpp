class Solution {
public:
    pair<int,int> check(string s, int l, int  r){
        while(l >= 0 && r < s.size() && s[l] == s[r]){
            l--;
            r++;
        }
        return {l+1,r-l-1};
    }

    string longestPalindrome(string s) {
        int maxlen = 0;
        string res = "";
        for(int i = 0 ; i <s.size() ; ++i){
            pair<int,int> even = (i+1 < s.size()) ? check(s,i,i+1) : pair<int,int>{0,0} ;
            pair<int,int> odd = check(s, i, i);
            if(odd.second > maxlen){
                res = s.substr(odd.first,odd.second); 
                maxlen = odd.second;
            }
            if(even.second > maxlen){
                res = s.substr(even.first,even.second);
                maxlen = even.second;
            } 
        }
        return res;
    }
};