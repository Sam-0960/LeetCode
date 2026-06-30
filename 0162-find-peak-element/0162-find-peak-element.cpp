class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        if(nums.size() == 2) return (nums[0] > nums[1])? 0:1;
        int low = 0;
        int high = nums.size()-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(low == 0 && nums[low] > nums[low+1]) return low;
            if(high == nums.size()-1  && nums[high] > nums[high-1]) return high;
            if(nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]) return mid;
            else if(nums[mid] > nums[mid-1]) low = mid;
            else high = mid;
        }
        return -1;
    }
};