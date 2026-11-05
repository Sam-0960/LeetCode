class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        pair<int,int> steps = {1,2};
        for(int i=3; i<=n ;i++){
            int sum = steps.first + steps.second;
            steps.first = steps.second;
            steps.second = sum;
        }
        return steps.second;
    }
};