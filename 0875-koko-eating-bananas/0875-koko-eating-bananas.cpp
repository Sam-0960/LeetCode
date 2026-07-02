class Solution {
public:
    bool ispossible(vector<int>& piles, int h , long long mid){
        long long hrs = 0;
        for(int i = 0 ; i<piles.size(); i++){
            if(piles[i]%mid == 0) hrs += (piles[i]/mid);
            else hrs += ((piles[i]/mid)+1);
        }
        return (hrs <= h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long min = 1, max =*max_element(piles.begin(), piles.end());
        long long ans = -1;
        while(min  <= max){
            long long mid = min + (max-min)/2;
            if(ispossible(piles,h,mid)){
                ans = mid;
                max = mid-1;
            }else{
                min = mid+1;
            }
        }
        return (int)ans;
    }
};