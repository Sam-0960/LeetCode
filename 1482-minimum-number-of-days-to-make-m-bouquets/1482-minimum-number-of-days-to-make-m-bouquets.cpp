class Solution {
public:
    bool ispossible(vector<int>& nums, int m, int k , int mid){
        int bouquets = 0;
        int flag = 0;
        for(int i = 0 ; i<nums.size() ; i++){
            if(ceil((double)nums[i]/mid) == 1 && flag < k){
                flag++;
            }else{
                flag = 0;
            }
            if(flag == k ){
                flag = 0;
                bouquets++;
            }
        }
        return (bouquets >= m);
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(1LL* m * k> (long long)bloomDay.size()) return -1;
        long long min = 1, max = *max_element(bloomDay.begin(),bloomDay.end());
        long long ans = -1;
        while(min <= max){
            long long mid = min +(max-min)/2;
            if(ispossible(bloomDay,m,k,mid)){
                ans = mid;
                max = mid-1;
            }else{
                min = mid+1;
            }
        }
        return ans;
    }
};