class Solution {
public:
    int func(int index,int sum,vector<int>& nums,vector<vector<int>>& cache){
        sum = abs(sum);
        if(index == nums.size()) return sum;
        if(cache[index][sum] != -1) return cache[index][sum];
        //plus
        int plus = func(index+1,sum+nums[index],nums,cache);
        //minus
        int minus = func(index+1,sum-nums[index],nums,cache);
        return cache[index][sum] = min(plus,minus);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int total = accumulate(stones.begin(),stones.end(),0LL);
        vector<vector<int>> memo(stones.size()+1,vector<int> (total+1,-1));
        return func(0,0,stones,memo);
    }
};