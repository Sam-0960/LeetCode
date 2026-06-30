class Solution {
public:
    bool probable(vector<int>& weights, int days, int mid){
        int cnt = 1;
        int load = 0;
        for(int i= 0; i<weights.size(); i++){
            if( load + weights[i] <= mid){
                load += weights[i];
            }else{ 
                load = weights[i];
                cnt++;
            }
            if(cnt > days) return false;    
        }
        return (cnt <= days);
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int right = accumulate(weights.begin(),weights.end(),0);
        int left = *max_element(weights.begin(),weights.end());
        int ans = 0;
        while(left <= right){
            int mid = left + (right-left)/2;
            if( probable(weights, days, mid)){
                right = mid-1;
                ans = mid;
            }else{
                left = mid+1;
            }
        }
        return ans;
    }
};