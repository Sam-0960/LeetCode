class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long sum = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            int mini = nums[i];
            int maxi = nums[i];
            for(int j = i+1; j<nums.size() ;j++){
                if(nums[j] < mini) mini = nums[j];
                if(nums[j] > maxi) maxi = nums[j];
                sum += (maxi-mini);
            }
        } 
        return sum;
    }
};