class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        if(k == 0) return 0;
        long long lsum = 0 ,rsum = 0;
        for(int i = 0 ; i< k; i++) lsum += cardPoints[i];
        long long maxsum = lsum;
        int r = cardPoints.size() - 1;
        int l = k-1;
        while(k){
            rsum += cardPoints[r];
            lsum -= cardPoints[l--];
            r--;
            maxsum = max(maxsum , lsum + rsum);
            k--;
        }
        return maxsum;
    }
};