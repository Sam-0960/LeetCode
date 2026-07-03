class Solution {
public:
    vector<vector<int>> ans;
    void func(int index, vector<int>& arr,int target,vector<int>& candidates){
        if(target == 0){
            ans.push_back(arr);
            return;
        }
        else if(index == candidates.size()){
            return;// we need to stop the recursion as the tree reaches its ends and condn not met
        }else{
            if(candidates[index]<= target){
                arr.push_back(candidates[index]);
                func(index, arr, target-candidates[index],candidates);
                arr.pop_back();
                func(index+1, arr,target,candidates);
            }else return;
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> arr;
        sort(candidates.begin(),candidates.end());
        func(0,arr,target,candidates);
        return ans;
    }
};