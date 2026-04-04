class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int cnt = 0 ;
        int sum = 0;
        int total = accumulate(arr.begin(),arr.end(),0LL);
        if (total % 3 != 0) return false;
        int target = total/3;
        for(auto x: arr){
            sum+= x;
            if(sum == target){
                cnt++;
                sum = 0;
            }
        }
        return cnt >= 3;
    }
};