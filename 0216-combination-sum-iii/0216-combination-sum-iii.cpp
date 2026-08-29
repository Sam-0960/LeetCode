class Solution {
public:
    vector<vector<int>> ans;
    void f(int num,int sum, int k , int n , vector<int>& v){
        if(v.size() == k && sum == n){
            ans.push_back(v);
            return;
        }
        for(int i = num+1; i<= 9; i++){
            v.push_back(i);
            f(i,sum+i,k,n,v);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> v;
        f(0,0,k,n,v);
        return ans;
    }
};