class Solution {
public:
    pair<int,int> checkpal(string s, int start, int end){
        if(end >= s.size()) return {-1,0};
        while(start >=0 && end < s.size() && s[start] == s[end]){
            start--;end++;
        }
        int len = end-start-1;
        return {start+1,len};
    }
    string longestPalindrome(string s) {
        string res; int maxlen = 0;
        for(int i =0; i<s.size(); i++){
            pair<int,int> odd = checkpal(s,i,i);
            pair<int,int> even = checkpal(s,i,i+1);
            if(odd.second > maxlen){
                maxlen = odd.second;
                res = s.substr(odd.first,maxlen);
            }
            if(even.second > maxlen){
                maxlen = even.second;
                res = s.substr(even.first,maxlen);
            }
        }
        return res;
    }
};