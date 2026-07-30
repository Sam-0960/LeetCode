class Solution {
public:
    void func(int index,int target,vector<int>& candidates,vector<int>& v,vector<vector<int>>& ans){
        if(target < 0) return; //to stop pruning
        if(target == 0){
            ans.push_back(v);
            return;
        }else if(index == candidates.size()) return;
        else{
            // two possibilities
            //pick the same index number and proceed with the same
            if(candidates[index] <= target){
                v.push_back(candidates[index]);
                func(index,target - candidates[index],candidates,v,ans);
                v.pop_back();
            }
            //proceed to next number in list
            func(index+1,target,candidates,v,ans);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;vector<int> v;
        func(0,target,candidates,v,ans);
        return ans;
    }
};