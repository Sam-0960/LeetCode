class Solution {
public:
    vector<vector<int>> ans;
    void func(int index, vector<int>& arr, vector<int>& nums){
        ans.push_back(arr);
        if(index == nums.size()) return;
        for(int i = index ; i<nums.size() ; i++){
            arr.push_back(nums[i]);
            func(i+1,arr,nums);
            arr.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> arr;
        func(0,arr,nums);
        return ans;
    }
};