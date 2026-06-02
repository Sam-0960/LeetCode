class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l = 0 , r = 0;
        bool ans = false;
        unordered_map<char,int> mp;
        for(auto x:s1) mp[x]++;
        int cnt = s1.size();
        for(int r = 0; r<s2.size(); ++r){
            mp[s2[r]]--;
            if(mp[s2[r]] >= 0) cnt--;
            while(cnt == 0){
                if(r-l+1 == s1.size()) ans = true;
                mp[s2[l]]++;
                if(mp[s2[l]] > 0)cnt++;
                l++;
            }
        }
        return ans;
    }
};