class Solution {
public:
    vector<int> next_perm(vector<int> nums){
        if(nums.size() == 0) return {};
        if(nums.size() == 1) return {nums[0]};

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
            return nums;
        }
        int el_ind = dip+1;
        for(int i=dip+1; i<n;i++){
            if(nums[i] > nums[dip] && nums[el_ind] >= nums[i] ) el_ind = i;
        }
        swap(nums[dip], nums[el_ind]);
        sort(nums.begin()+dip+1, nums.end());
        return nums;
    }
    int fact(int n){
        if(n == 0 || n == 1) return 1;
        return n * fact(n-1);
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int j = nums.size();    
        int n = fact(j);
        vector<vector<int>> ans;
    
        for(int i = 0 ; i < n ; i++){
            ans.push_back(nums);
            nums = next_perm(nums);
        }
        return ans;
    }
};