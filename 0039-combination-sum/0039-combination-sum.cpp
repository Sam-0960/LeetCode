class Solution {
public:
    vector<vector<int>>  ans;
    void f(int index , int target, vector<int>& v, vector<int>& candidates){
        if(target == 0){
            ans.push_back(v);
            return;
        }else if(index ==  candidates.size()) return;
        else{
            if(target >= candidates[index]){
                v.push_back(candidates[index]);
                f(index,target-candidates[index],v,candidates);
                v.pop_back();
            }
            f(index+1,target,v,candidates);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        f(0,target,v,candidates);
        return ans;
    }
};