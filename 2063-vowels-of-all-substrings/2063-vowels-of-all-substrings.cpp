class Solution {
public:
    long long countVowels(string word) {
        long long ans = 0;
        int n = word.size();
        for(int i = 0 ; i<n ; i++){
            if( word[i] == 'a'||
                word[i] == 'e'||
                word[i] == 'i'||
                word[i] == 'o'||
                word[i] == 'u'
            ){ 
                long long m1 =(i+1);
                long long m2 = n-i;
                ans += m1*m2;
            }
        }
        return ans;
    }
};