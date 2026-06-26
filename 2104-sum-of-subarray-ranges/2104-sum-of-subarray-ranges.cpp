class Solution {
public:
    long long sumSubarraymins(vector<int>& nums){
        vector<long long> pse;
        vector<long long> nse;
        stack<long long> st;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            if(st.empty()) pse.push_back(i+1);
            else pse.push_back(i - st.top());
            st.push(i);
        }
        st = stack<long long> ();
        for(int i = n-1; i>= 0; i--){
            while(!st.empty() && nums[st.top()] > nums[i]) st.pop();
            if(st.empty()) nse.push_back(n-i);
            else nse.push_back(st.top()-i);
            st.push(i);
        }
        long long sum = 0;
        for(int i = 0 ; i<n ; i++){
            long long left = pse[i] ,  right = nse[n-i-1];
            sum = sum + (1LL*nums[i]*left*right);
        }
        return sum;
    }

    long long sumSubarraymaxs(vector<int>& nums){
        vector<long long> pge;
        vector<long long> nge;
        stack<long long> st;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            if(st.empty()) pge.push_back(i+1);
            else pge.push_back(i - st.top());
            st.push(i);
        }
        st = stack<long long> ();
        for(int i = n-1; i>= 0; i--){
            while(!st.empty() && nums[st.top()] < nums[i]) st.pop();
            if(st.empty()) nge.push_back(n-i);
            else nge.push_back(st.top()-i);
            st.push(i);
        }
        long long sum = 0;
        for(int i = 0 ; i<n ; i++){
            long long left = pge[i] ,  right = nge[n-i-1];
            sum = sum + (1LL*nums[i]*left*right);
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        long long sum1 = sumSubarraymins(nums);
        long long sum2 = sumSubarraymaxs(nums);
        return sum2 - sum1;
    }
};