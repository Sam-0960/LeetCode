class Solution {
public:
    vector<vector<int>> ans;
    void func(int index, int k , int n , vector<int>& arr){
        if(n == 0 && k == 0){
            ans.push_back(arr);
            return;
        }
        for(int i=index; i<= 9 ; i++){
            arr.push_back(i);
            func(i+1,k-1,n-i,arr);
            arr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr;
        func(1,k,n,arr);
        return ans;
    }
};