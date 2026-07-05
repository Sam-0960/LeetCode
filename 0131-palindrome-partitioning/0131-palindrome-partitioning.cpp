class Solution {
public:
    bool check(string s, int start , int end){
        while(start < end){
            if(s[start]!= s[end]) return false;
            start++;end--;
        }
        return true;
    }

    vector<vector<string>> ans;
    void func(int index, vector<string>& arr, string s ){
        if(index == s.size()){
            ans.push_back(arr);
            return;
        }
        for(int i=index; i<s.size(); i++){
            if(check(s, index, i)){
                string p =s.substr(index, i-index+1);
                arr.push_back(p);
                func(i+1,arr,s);
                arr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> arr;
        func(0,arr,s);
        return ans;
    }
};