class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(),0LL);
        int maxSum = INT_MIN;
        int minSum = INT_MAX;
        int currMax = 0;
        int currMin = 0;

        for(auto x: nums){
            currMax += x;
            maxSum = max(maxSum , currMax);
            if(currMax < 0) currMax = 0;

            currMin += x;
            minSum = min(minSum, currMin);
            if(currMin > 0) currMin = 0;
        }
        return (maxSum > 0)? max(maxSum, total-minSum):maxSum;
    }
};