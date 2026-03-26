class Solution {
public:
    long long countVowels(string word) {
        int r = 0;
        long long ans = 0;
        int n = word.size();
        while(r < word.size()){
            if( word[r] == 'a' ||
                word[r] == 'e' ||
                word[r] == 'i' ||
                word[r] == 'o' ||
                word[r] == 'u' ){
                    long long m1 = (r+1);
                    long long m2 = (n-r);
                    ans += m1*m2;
                }
            r++;
        }
        return ans;
    }
};