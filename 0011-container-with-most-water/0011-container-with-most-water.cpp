class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() <= 1) return 0;
        int water = INT_MIN;
        int l = 0;
        int r = height.size()-1;

        while(l<r){
            int curr = min(height[l],height[r]) * (r-l);
            water = max(curr,water);
            if(height[l] >= height[r]){
                r--;
            }else l++;
        }
        return water;
    }
};