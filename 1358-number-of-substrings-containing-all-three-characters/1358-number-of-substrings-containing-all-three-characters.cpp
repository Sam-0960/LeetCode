class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        unordered_map<char,int> mp;
        int l = 0 ; int r = 0;
        int n = s.size();
        while(r<s.size()){
            mp[s[r]]++;
            if(mp.size() == 3) ans += (n-r);

            while(mp.size() == 3){
                mp[s[l]]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                if(mp.size() == 3) ans += (n-r);
                l++;
            }
            
            r++;
        }
        return ans;
    }
};