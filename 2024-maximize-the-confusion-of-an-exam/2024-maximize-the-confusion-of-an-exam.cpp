class Solution {
public:
    int maxlen(string arr , int k , int c){
        int cnt = 0;
        int l = 0 ; 
        int r = 0;
        int maxlen = 0;
        while(r<arr.size()){
            if(arr[r] != c) cnt++;
            if(cnt > k){
                while(cnt != k){
                    if(arr[l] != c) cnt--;
                    l++;
                }
            }
            maxlen = max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(maxlen(answerKey,k ,'T'),maxlen(answerKey,k ,'F'));
    }
};