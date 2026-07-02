class Solution {
public:
    bool possible(vector<int>& weights, int days, long long mid){
        long long load = 0;
        long long Days = 1;
        for(auto x: weights){
            if(load + x > mid){
                load = x;
                Days++;
            }else{
                load += x;
            }
        }
        return (Days <= days);
    }
    int shipWithinDays(vector<int>& weights, int days) {
        long long max = accumulate(weights.begin(),weights.end(),0LL);
        long long min = *max_element(weights.begin(),weights.end());
        long long ans = min;
        while(min <= max){
            long long mid = min + (max-min)/2;
            if(possible(weights,days,mid)){
                ans = mid;
                max = mid-1;
            }else{
                min = mid+1;
            }
        }
        return ans;
    }
};