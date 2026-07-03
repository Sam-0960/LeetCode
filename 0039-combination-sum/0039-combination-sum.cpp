class Solution {
public:
    vector<vector<int>> ans;
    void f(int ind,int target,vector<int>& v,vector<int>& candidates){
        if(target == 0){
            ans.push_back(v);
            return;
        }
        else if(candidates.size() == ind) return;
        else if(candidates[ind] <= target){
            v.push_back(candidates[ind]);
            f(ind,target-candidates[ind],v,candidates);
            v.pop_back();
        }
        f(ind+1,target,v,candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        f(0,target,v,candidates);
        return ans;
    }
};