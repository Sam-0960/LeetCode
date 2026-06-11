class Solution {
public:
    string reverseWords(string s) {
        int l = 0 ;int r  =  s.size() - 1;
        while(s[l] == ' ') l++;
        while(s[r] == ' ') r--;
        string res = s.substr(l,r-l+1);
         l = 0 , r = 0;
        while(r<res.size()){
            l = r;
            while(r<res.size() && res[r]!= ' ') r++;
            reverse(res.begin()+l,res.begin()+r);
            r++;
        }
        reverse(res.begin(),res.end());
        int cnt = 0;
        for(int i = 0; i<res.size(); ++i){
            if(res[i] == ' ') cnt++;
            else{
                cnt = 0;
            }
            if(cnt >  1 ){
                res.erase(i,1);
                i--;
            }
        }
        return res;
    }
};