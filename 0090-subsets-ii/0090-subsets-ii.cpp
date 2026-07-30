class Solution {
public:
    void f(int index,vector<int>& nums,vector<int>& v,vector<vector<int>>& ans){
        ans.push_back(v);
        for(int i = index; i<nums.size();i++){
            if(i>index && nums[i] == nums[i-1]) continue;
            v.push_back(nums[i]);
            f(i+1,nums,v,ans);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> v;
        f(0,nums,v,ans);
        return ans;
    }
};