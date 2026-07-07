class Solution {
public:
    vector<int> next_permut(vector<int>& nums){
        int dip = -1;
        for(int i = nums.size()-1; i>=1; i--){
            if(nums[i-1] < nums[i]){
                dip = i-1;
                break;
            }
        }
        if(dip == -1){
            reverse(nums.begin(),nums.end());
            return nums;
        }
            int index = nums.size()-1;
        for(int i = nums.size()-1; i>= dip ;i--){
            if(nums[dip] < nums[i]){
                index = i;
                break;
            }
        }
        swap(nums[index],nums[dip]);
        reverse(nums.begin()+dip+1, nums.end());
        return nums;
    }
    int fact(int n){
        if(n == 0 || n == 1) return 1;
        return n*fact(n-1);
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = fact(nums.size());
        for(int i = 0; i <n; i++){
            ans.push_back(nums);
            nums = next_permut(nums);
        }
        return ans;
    }
};