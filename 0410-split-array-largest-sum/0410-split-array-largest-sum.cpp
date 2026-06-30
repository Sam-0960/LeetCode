class Solution {
public:
    bool possible(vector<int>& nums, int k ,int mid){
        int cnt = 1;
        int load = 0;
        for(int i=0 ; i<nums.size(); i++){
            if(load + nums[i] > mid){
                load = nums[i];
                cnt++;
            }
            else{
                load += nums[i];
            }
            if(cnt > k) return false;
        }
        return (cnt <= k);
    }
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(),0);
        int ans = 0;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(possible(nums,k,mid)){
                ans = mid;
                r = mid-1;
            }else{
                l = mid +1;
            }
        }
        return ans;
    }
};