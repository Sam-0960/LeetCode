class Solution {
public:
    vector<string> keypad = {"","", "abc", "def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> ans;
    void func(int index, string digits, string arr){
        if(index == digits.size()){
            ans.push_back(arr);
            return;
        }
        for(int i = 0; i<keypad[(digits[index]-'0')].size();i++){
            arr.push_back(keypad[digits[index] - '0'][i]);
            func(index+1,digits,arr);
            arr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string arr;
        func(0,digits,arr);
        return ans;
    }
};