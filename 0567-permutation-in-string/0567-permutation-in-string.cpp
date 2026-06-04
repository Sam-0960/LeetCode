class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> mp;
        for(auto x: s1) mp[x]++;
        int cnt = s1.size();
        int l = 0 , r = 0;
        while(r < s2.size()){
            mp[s2[r]]--;
            if(mp[s2[r]]>=0) cnt--;
            while(cnt==0){
                if(r-l+1 == s1.size()) return true;
                mp[s2[l]]++;
                if(mp[s2[l]] > 0) cnt++;
                l++;
            }
            r++;
        }
        return false;
    }
};