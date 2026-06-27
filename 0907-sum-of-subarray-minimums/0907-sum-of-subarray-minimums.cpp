class Solution {
public:
    vector<int> Nse(vector<int>& arr){
        vector<int> ans;
        stack<int> st;
        int n = arr.size();
        for(int i = n-1 ; i>= 0 ; i--){
            while(!st.empty() && arr[st.top()] >= arr[i] ) st.pop();
            if(st.empty()) ans.push_back(n-i);
            else ans.push_back(st.top()-i);
            st.push(i);
        }
        return ans;
    }
    vector<int> Pse(vector<int>& arr){
        vector<int> ans;
        stack<int> st;
        int n = arr.size();
        for(int i = 0 ; i<n ; i++){
            while(!st.empty() && arr[st.top()] > arr[i] ) st.pop();
            if(st.empty()) ans.push_back(i+1);
            else ans.push_back(i-st.top());
            st.push(i);
        }
        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = Nse(arr);
        vector<int> pse = Pse(arr);
        long long sum = 0;
        const int mod = 1e9+7;
        for(int i = 0 ; i<arr.size(); i++){
            sum = ((sum + 1LL *arr[i]*(pse[i]*nse[arr.size()-i-1]) )% mod);
        }
        
    return (int) (sum);
    }  
};