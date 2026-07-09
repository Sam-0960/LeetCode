class Solution {
public:
    vector<string> ans;
    void func(int index, string nums, string s, int target , long long eval, long long residual){
        if(index == nums.size()){
            if(eval == (long long) target) ans.push_back(s);
            return;
        }
        string curr;
        long long num = 0;
        for(int i= index; i<nums.size() ;i++){
            if( i>index && nums[index] == '0') break;
            curr += nums[i];
            num = num*10 + (nums[i]-'0');
            if( index == 0) func(i+1,nums,s+curr,target,num,num);
            else{
                func(i+1, nums,s+'+'+curr,target,eval+num,num);
                func(i+1, nums,s+'-'+curr,target,eval-num,-num);
                func(i+1,nums,s+'*'+curr,target,eval-residual+num*residual,residual*num);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        func(0,num,"",target,0,0);
        return ans;
    }
};