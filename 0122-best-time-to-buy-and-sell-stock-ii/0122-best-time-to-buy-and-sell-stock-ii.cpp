class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> ans(n,0);
        int cntr = 0;
        int start = 0;
        for(int i=1; i<prices.size(); i++){
            if(prices[i] < prices[start]){
                start = i;
                continue;
            }
            int profit = prices[i] - prices[start];
            if(profit > 0){
                ans.push_back(profit);
                start = i;
            }
        }
        int sum = 0;
        for(auto x:ans) sum += x;
        return sum;
    }
};