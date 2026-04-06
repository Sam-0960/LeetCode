class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxsum = INT_MIN;
        int curr = 0;
        int minsum = INT_MAX;
        int c = 0;
        for(auto x: nums){
            curr += x;
            c += x;
            minsum = min(minsum, c);
            if(c > 0) c = 0;
            maxsum = max(maxsum, curr);
            if(curr < 0) curr = 0;
            cout << minsum<<endl;
            cout << maxsum <<endl;
        }
        return max(maxsum,abs(minsum));
    }
};