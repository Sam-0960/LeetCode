class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        pair<int,int> dp = {1,2};
        for(int i=3 ;i<=n; i++){
            int next = dp.first + dp.second;
            dp.first = dp.second;
            dp.second = next;
        }
        return dp.second;
    }
};