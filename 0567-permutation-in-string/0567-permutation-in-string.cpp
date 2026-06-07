class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int hash[26] = {0};
        for(auto x:s1) hash[x-'a']++;
        int cnt = s1.size();
        int l = 0;
        for(int i = 0; i<s2.size() ; ++i ){
            hash[s2[i]-'a']--;
            if(hash[s2[i] -'a'] >= 0) cnt--;
            while(cnt == 0){
                hash[s2[l] -'a']++;
                if(i-l+1 == s1.size()) return true;
                if(hash[s2[l] -'a'] > 0) cnt++;
                ++l;
            }
        }
        return false;
    }
};