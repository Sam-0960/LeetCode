class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0) return 0;
        int prod = 1;
        int count = 0;
        int l=0,r=0;
        while( l<=r && r<nums.size()){
            prod *= nums[r];

            while(prod >= k){
                prod /= nums[l];
                l++;
                
                if(l > nums.size()) break;
            }
            count += (r-l+1);
            r++;
        }
        if(count<0) return 0;
        else return count;
    }
};