class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());
        prefix[0] = nums[0];
        cout << prefix[0] <<endl;
        for(int i = 1 ; i< nums.size();i++){
            prefix[i] = nums[i] * prefix[i-1];
            cout << prefix[i] <<endl;
        }
        suffix[nums.size()-1] = nums[nums.size()-1];
        cout << suffix[nums.size()-1] << endl;
        for(int i = nums.size()-2; i>=0; i--){
            suffix[i] = suffix[i+1]*nums[i];
            cout << suffix[i] <<endl;
        }

        vector<int> ans(nums.size());
        ans[0] = suffix[1];
        ans[nums.size()-1] = prefix[nums.size()-2];
        for(int i=1; i<=nums.size()-2; i++){
            ans[i] = prefix[i-1] * suffix[i+1];
        }
        return ans;
    }
};