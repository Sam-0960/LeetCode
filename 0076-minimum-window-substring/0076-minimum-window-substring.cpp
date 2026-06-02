class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(auto x: t) mp[x]++;
        int l = 0 ; int r = 0;
        int len = INT_MAX;
        int cnt = t.size();
        int start = -1;
        while(r<s.size()){
            mp[s[r]]--;
            if(mp[s[r]] >= 0) cnt--;
            while(cnt == 0){
                if(r-l+1 < len){ 
                    start = l;
                    len = r-l+1;
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0) cnt++;
                l++;
            }
            r++;
        }
        return (start == -1)? "": s.substr(start,len);
    }   
};