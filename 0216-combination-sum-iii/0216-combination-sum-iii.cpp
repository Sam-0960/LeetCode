class Solution {
public:
    vector<vector<int>> ans;
    void func(int ind ,vector<int>& arr, int count ,int k, int target){
        if(target == 0){
            if(count == k){
            ans.push_back(arr);
            return;
            }else return;
        }
        for(int i = ind; i<=9; i++){
            arr.push_back(i);
            func(i+1,arr,count+1,k,target-i);
            arr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr;
        func(1,arr,0,k,n);
        return ans;
    }
};