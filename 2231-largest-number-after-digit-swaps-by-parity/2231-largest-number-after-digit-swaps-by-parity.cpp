class Solution {
public:
    int largestInteger(int num) {
        if(num == 0) return 0;
        string ans = "";
        vector<int> e, o;
        vector<int> nums;
        while(num){
            int rem = num%10;;
            if(rem%2 == 0){e.push_back(rem);nums.push_back(0);}
            else {o.push_back(rem);nums.push_back(1);}
            num = num/10;
        }
        reverse(nums.begin(),nums.end());
        sort(e.begin(),e.end(), greater<int> ());
        sort(o.begin(),o.end(), greater<int> ());
        int l = 0 , k = 0;
        for(auto i = 0 ; i<nums.size() ; ++i){
            if(nums[i] == 0 ) ans.push_back(e[l++]+'0');
            else ans.push_back(o[k++] + '0');
        }
        int res = stoi(ans);
        return res;
    }
};