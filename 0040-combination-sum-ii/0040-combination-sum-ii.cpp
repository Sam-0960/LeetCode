class Solution {
public:
    vector<vector<int>> ans;
    void f(int index, int target, vector<int> v, vector<int> candidates){
        if(target == 0){
            ans.push_back(v);
            return;
        }
        for(int i = index; i<candidates.size();i++){
            if(i>index && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] >  target) break;
            v.push_back(candidates[i]);
            f(i+1,target - candidates[i],v,candidates);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> v;
        f(0,target,v,candidates);
        return ans;
    }
};