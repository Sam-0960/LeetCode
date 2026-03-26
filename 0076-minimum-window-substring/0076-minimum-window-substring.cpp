class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(auto x: t) mp[x]++;

        int count = 0;
        int n = mp.size();
        int l = 0 ,r = 0;
        int minlen = INT_MAX;
        int sindex = -1;
        while(r<s.size()){
            mp[s[r]]--;
            if(mp[s[r]] == 0) count++;
            while( count == n){
                if(minlen > r-l+1){
                        minlen = r-l+1;
                        sindex = l;
                }
                mp[s[l]]++;
                if(mp[s[l]] > 0){
                    count--;
                }
                l++;
            }
            r++;
        }
        return (sindex == -1)? "" : s.substr(sindex,minlen);
    }
};