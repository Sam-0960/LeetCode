class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        if(n == 1) return stones[0];
        sort(stones.begin(),stones.end(),greater<int>());
        while(true){
            if(stones[1] == 0) return stones[0];
            if(stones[0] == stones[1]){
                stones[0] = stones[1] = 0;

            }else{
                stones[0] -= stones[1];
                stones[1] = 0;

            }
            sort(stones.begin(),stones.end(),greater<int>());
        }
        return stones[0];
    }
};