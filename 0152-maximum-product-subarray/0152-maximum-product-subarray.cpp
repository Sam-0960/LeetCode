class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        int prefix = 1;
        int suffix = 1;
        int maxprod = 0;
        int n = nums.size();
        for(int i = 0  ; i<nums.size(); i++){
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;
            prefix *= nums[i];
            suffix *= nums[n-i-1];
            maxprod = max(maxprod, max(prefix,suffix));
        }
        return maxprod;
    }
};