class Solution {
public:
    void f(int ind,int target, vector<int>& arr,vector<int>& candidates,vector<vector<int>>& ans){
        if(target == 0){
            ans.push_back(arr);
            return;
        }else{
            for(int i = ind; i<candidates.size(); i++){
                if(i>ind && candidates[i] == candidates[i-1]) continue;
                else if(candidates[i] > target) break;
                else{
                    arr.push_back(candidates[i]);
                    f(i+1,target-candidates[i], arr,candidates,ans);
                    arr.pop_back();
                }
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        f(0,target,v,candidates,ans);
        return ans;
    }
};