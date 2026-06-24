class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() < 3) return 0;
        int lmax = 0 , rmax  = 0;
        int l = 0 , r = height.size()-1;
        int water = 0;
        while(l < r){
            lmax = max(lmax,height[l]);
            rmax = max(height[r],rmax);
            if(lmax < rmax){ water += (lmax - height[l]); l++;}
            else { water += (rmax - height[r]); r--;}
        }
        return water;
    }
};