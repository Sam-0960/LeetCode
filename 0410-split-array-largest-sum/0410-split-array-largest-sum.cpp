class Solution {
public:
    bool isPossible(vector<int>& nums, int k, int mid){
        int load = 0;
        int curr = 1;
        for(auto x: nums){
            if(load+ x <= mid){
                load+=x;
            }else{
                load = x;
                curr++;
            }
        }
        return (curr <= k)? true :false;
    }
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(),nums.end());
        int high = accumulate(nums.begin(),nums.end(),0LL);

        int ans = 0;
        while( low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(nums,k,mid)){
                ans = mid;
                high = mid-1;
            }else low = mid +1;
        }
        return ans;
    }
};