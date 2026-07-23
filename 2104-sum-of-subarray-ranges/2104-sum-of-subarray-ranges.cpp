class Solution {
public:
    void find(vector<int>& nums,vector<long long>& pse,vector<long long>& nse,vector<long long>& pge,vector<long long>& nge){
        int n = nums.size();
        stack<int> st;
        for(int i = n-1; i>= 0 ; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            if(st.empty()) nse.push_back(n-i);
            else nse.push_back(st.top()-i);
            st.push(i);
        }
        st =  stack<int> ();
        for(int i = n-1; i>= 0 ; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            if(st.empty()) nge.push_back(n-i);
            else nge.push_back(st.top()-i);
            st.push(i);
        }
        st =  stack<int> ();
        for(int i = 0; i<n ; i++){
            while(!st.empty() && nums[st.top()] < nums[i]) st.pop();
            if(st.empty()) pge.push_back(i+1);
            else pge.push_back(i-st.top());
            st.push(i);
        }
        st =  stack<int> ();
        for(int i = 0; i<n ; i++){
            while(!st.empty() && nums[st.top()] > nums[i]) st.pop();
            if(st.empty()) pse.push_back(i+1);
            else pse.push_back(i-st.top());
            st.push(i);
        }

        return ;
    }
    long long subArrayRanges(vector<int>& nums) {
        vector<long long> nse, pse,pge,nge;
        find(nums,pse,nse,pge,nge);
        long long sum1= 0, sum2 = 0;
        for(int i=0; i<nums.size() ; i++){
            sum1 += ((nums[i]*1LL)*nse[nums.size()-i-1]*pse[i]);
            sum2 += ((nums[i]*1LL)*nge[nums.size()-i-1]*pge[i]);
            
        }
        return sum2-sum1;
    }
};