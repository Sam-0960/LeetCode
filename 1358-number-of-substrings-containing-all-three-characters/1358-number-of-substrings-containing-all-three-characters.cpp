class Solution {
public:
    int numberOfSubstrings(string s) {
        int l =0,r=0;
        unordered_map<char,int> mp;
        int n = s.size();
        int res = 0;
        mp['a'] = 0;mp['b'] = 0;mp['c'] = 0;
        mp[s[r]]++;
        while( r<s.length()){
            while(r<n && (mp['a'] < 1 || mp['b'] < 1 || mp['c'] < 1) ){  
                r++;    
                mp[s[r]]++;            
            }

            res += n-r;
            mp[s[l]]--;
            l++;
        }
        return res;
    }
};