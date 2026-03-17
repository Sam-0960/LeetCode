class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 0) return;
        if(nums.size() == 1) return;

        int dip = -1;
        int n =nums.size();
        for(int i=n-1; i>0;i--){
            if(nums[i] > nums[i-1]){
                dip = i-1;
                break;
            }
        }
        if(dip == -1){ 
            reverse(nums.begin(),nums.end());
            return;
        }
        int el_ind = dip+1;
        for(int i=dip+1; i<n;i++){
            if(nums[i] > nums[dip] && nums[el_ind] >= nums[i] ) el_ind = i;
        }
        swap(nums[dip], nums[el_ind]);
        sort(nums.begin()+dip+1, nums.end());
        return;
    }
};