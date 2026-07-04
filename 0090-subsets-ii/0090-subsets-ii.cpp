class Solution {
public:
    vector<vector<int>> ans;
    void func(int index, vector<int>& arr, vector<int>& nums){
        ans.push_back(arr);
        if(index == nums.size()) return;
        for(int i = index; i<nums.size();i++){
            if( i>index && nums[i] == nums[i-1]) continue;
            arr.push_back(nums[i]);
            func(i+1,arr,nums);
            arr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> c;
        sort(nums.begin(),nums.end());
        func(0,c,nums);
        return ans;
    }
};