class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0;
        unordered_map<char, int> mp;
        int maxlen = 0;
        while (l <= r && r < s.size()) {

            while (mp.find(s[r]) != mp.end()) {
                mp.erase(s[l]);
                l++;
            }

            mp[s[r]]++;
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};