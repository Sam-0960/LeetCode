class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        vector<int> nse, pse, nge, pge;
        stack<int> st;
        int n = nums.size();
        for(int  i = n-1; i>=0 ; i--){
            while(!st.empty() && nums[st.top()]>= nums[i]) st.pop();
            if(st.empty()) nse.push_back(n-i);
            else nse.push_back(st.top()-i);
            st.push(i);
        }
        st = stack<int> ();
        for(int  i = 0; i<n ; i++){
            while(!st.empty() && nums[st.top()]> nums[i]) st.pop();
            if(st.empty()) pse.push_back(i+1);
            else pse.push_back(i-st.top());
            st.push(i);
        }
        st = stack<int> ();
        for(int i=n-1; i>= 0 ; i--){
            while(!st.empty() && nums[st.top()]<= nums[i]) st.pop();
            if(st.empty()) nge.push_back(n-i);
            else nge.push_back(st.top()-i);
            st.push(i);
        }
        st = stack<int> ();
        for(int  i = 0; i<n ; i++){
            while(!st.empty() && nums[st.top()]< nums[i]) st.pop();
            if(st.empty()) pge.push_back(i+1);
            else pge.push_back(i-st.top());
            st.push(i);
        }
        long long sum1 = 0 ,sum2 = 0;
        for(int i=0;i<n;i++){
            sum2 += (1LL*nums[i]*(pge[i]*nge[n-i-1]));
            sum1 += (1LL*nums[i]*(nse[n-i-1]*pse[i]));
        }
        return sum2-sum1;
    }
};