class Solution {
public:
    int maxTrue(string arr, int k){
        int maxlen = 0;
        int count = 0;
        int l=0,r=0;
        while( l<= r && r<arr.length()){
            if(arr[r] == 'F'){
                if(count < k){
                    count++;
                }else{
                    while(arr[l] == 'T') l++;
                    l++;
                }
            }
            maxlen = max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
    int maxFalse(string arr, int k){
        int maxlen = 0;
        int count = 0;
        int l =0,r=0;
        while( l<=r && r<arr.size()){
            if(arr[r] == 'T'){
                if(count < k){
                    count++;
                }else{
                    while(arr[l] == 'F') l++;
                    l++;
                }
            }
            maxlen = max(maxlen , r-l+1);
            r++;
        }
        return maxlen;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(maxTrue(answerKey,k),maxFalse(answerKey,k));
    }
};