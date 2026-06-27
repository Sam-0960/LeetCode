class Solution {
public:
    int trap(vector<int>& height) {
        int left = INT_MIN , right = INT_MIN;
        long long water = 0;
        int l = 0 ;int r = height.size()-1;
        while( l < r){
            left = max(left,height[l]);
            right = max(right,height[r]);
            if(left < right){
                water += (left -height[l]);
                l++;
            }else{
                water += (right -height[r]);
                r--;
            }
        }
        return (int) water;
    }
};