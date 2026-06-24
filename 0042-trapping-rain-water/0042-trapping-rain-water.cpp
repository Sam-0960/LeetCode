class Solution {
public:
    int trap(vector<int>& height) {
        int pref[height.size()], suf[height.size()];
        pref[0] = 0;
        for(int i = 1; i<height.size();++i){
            pref[i] = max(pref[i-1],height[i-1]);
        }
        suf[ height.size()-1] = 0;
        for(int i = height.size()-2; i>=0 ; i--){
            suf[i] = max(height[i+1],suf[i+1]);
        }

        long long water = 0;
        for(int i = 0 ; i<height.size() ;i++){
            if(min(pref[i],suf[i]) - height[i] > 0)
                water += min(pref[i],suf[i]) - height[i];
        }

        return (int) water;
    }
};