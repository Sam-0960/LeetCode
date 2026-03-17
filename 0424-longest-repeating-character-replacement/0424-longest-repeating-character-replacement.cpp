class Solution {
public:
    int maxletter(string s, int k, char X) {
        int l = 0, r = 0;
        int count = 0;
        int maxlen = 0;
        while (l <= r && r < s.length()) {
            if (s[r] != X) {
                count++;
            }
            while (count > k) {
                if (s[l] != X)
                    count--;
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        for (auto x : s)
            mp[x]++;
        int maxlen = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            maxlen = max(maxlen, maxletter(s, k, it->first));
        }
        return maxlen;
    }
};