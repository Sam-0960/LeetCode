class Solution {
public:
    bool isPossible(vector<int>& nums, int k , int mid){
        int curr = 1;
        int currsum = 0;
        for(auto x: nums){
            if(currsum+x > mid){
                currsum = x;
                curr++;
            }else{
                currsum += x;
            }
        }
        return (curr <= k)? true: false;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0LL);
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(nums,k,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid +1;
            }
        }
        return ans;
    }
};