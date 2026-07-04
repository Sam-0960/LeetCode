class Solution {
public:
    vector<string> ans;
    void func(int n, int num, string s){
        if(n == 0){
            ans.push_back(s);
            return;
        }
        if(num == 0){
            s.push_back('1');
            num = 1;// i need to push 1 forcefully because my prev number was 0
            func(n-1,num,s);
            s.pop_back();
            num = 0;
        }else{
            s.push_back('1');
            num = 1;
            func(n-1,num,s);
            s.pop_back();
            num = 0;
            s.push_back('0');
            func(n-1,num,s);
            s.pop_back();
            num = 1;
        }
    }
    vector<string> validStrings(int n) {
        string s;
        func(n,1,s);
        return ans;
    }
};