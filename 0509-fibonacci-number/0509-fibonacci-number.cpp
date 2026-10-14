class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        pair<int,int> dp = {0,1};
        for(int i=3; i<= n; i++){
            int val = dp.second;
            dp.second = dp.first + dp.second;
            dp.first = val;
        }
        return dp.second+dp.first;
    }
};