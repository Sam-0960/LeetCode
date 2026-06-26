class Solution {
public:
    vector<int> Nse(vector<int>& arr){
        stack<int> st;
        int n = arr.size();
        vector<int> v;
        for(int i=n-1 ; i>= 0 ; i--){
            int el = arr[i];
            while(!st.empty() && arr[st.top()] >= el) st.pop();
            if(st.empty()) v.push_back(n-i);
            else v.push_back(st.top()-i);
            st.push(i);
        }
        return v;
    }

    vector<int> Pse(vector<int>& arr){
        stack<int> st;
        int n = arr.size();
        vector<int> v;
        for(int i=0 ; i< n; i++){
            int el = arr[i];
            while(!st.empty() && arr[st.top()] > el) st.pop();
            if(st.empty()) v.push_back(i+1);
            else v.push_back(i-st.top());
            st.push(i);
        }
        return v;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = Nse(arr);
        vector<int> pse = Pse(arr);

        int n = arr.size();
        long long sum = 0;
        int val = 1e9+7;
        for(int i = 0 ; i<n; i++){
            long long left = pse[i], right =  nse[n-i-1];
            sum = (sum + (1LL*arr[i]*(left*right)))%val;
        }
        return (int) sum;
    }
};