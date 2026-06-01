class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        int l = 0 ; int r = 0;
        int ans = INT_MAX;
        unordered_map<char,int> mp;
        for(auto x: s) mp[x]++;
        while(r<s.size()){
            mp[s[r]]--;
            while(
                mp['Q'] <= n/4 && mp['W'] <= n/4 &&
                mp['E'] <= n/4 && mp['R'] <= n/4 && l<n
            ){
                ans = min(ans, r-l+1);
                mp[s[l]]++;
                l++;
            }
            r++;
        }
        return (ans == INT_MAX)? 0 : ans;

    }
};