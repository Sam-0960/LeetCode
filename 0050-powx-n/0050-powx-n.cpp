class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long long nn = n ;
        if(nn < 0) nn = -1* nn;
        while(nn){
            if( fmod(nn,2.0) == (double)1.00){
                ans = ans * x;
                nn = nn -1;
            }else{
                x = x*x;
                nn = nn/2;
            }
        }
        if(n < 0) ans = double(1.00) / double(ans);
        return ans;
    }
};