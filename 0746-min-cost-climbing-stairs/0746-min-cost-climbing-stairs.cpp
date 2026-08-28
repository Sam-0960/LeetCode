class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int n = cost.size();
        if(n == 3){
            return min(cost[1], cost[0]+cost[2]);
        }
        for(int i=2 ; i<n ; i++){
            cost[i] += min(cost[i-1],cost[i-2]); 
        }
        return cost[n-1];
    }
};