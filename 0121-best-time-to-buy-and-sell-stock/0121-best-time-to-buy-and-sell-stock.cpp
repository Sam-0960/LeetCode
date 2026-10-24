class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        int start= 0;
        for(int i = 1 ; i<n ; i++){
            if(prices[i] < prices[start]){
                start = i;
                continue;
            }
            ans = max(ans, prices[i] - prices[start]);
        }
        return  ans;
    }
};