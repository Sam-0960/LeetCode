class Solution {
public:
    bool isPossible(vector<int>& weights,int days, int mid){
        int load = 0;
        int curr_days = 1;
        for(auto x: weights){
            if(load + x > mid){
                curr_days++;
                load = x;
            }else{
                load += x;
            }
        }
        return (curr_days<= days)?true : false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(),weights.end(),0LL);
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(weights,days,mid)){
                ans = mid;
                high = mid - 1;
            }else low = mid+ 1;
        }
        return ans;
    }
};