class Solution {
public: 
    bool is(vector<int>& nums, int t, int mid){
        long long sum = 0;
        for(auto x: nums){
            sum += (ceil((double)x/mid));
        }
        return (sum <= t);
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        long long high = *max_element(nums.begin(),nums.end()), low = 1;
        long long ans = low;
        while(low <= high){
            long long mid = low + (high - low)/2;
            if(is(nums,threshold,mid)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return (int)ans;
    }
};