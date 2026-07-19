class Solution {
public: 
    void prevsmall(vector<int>& heights, vector<int>& pse){
        stack<int> st;
        for(int i=0; i<heights.size(); i++){
            int el = heights[i];
            while(!st.empty() && heights[st.top()] > el) st.pop();

            if(st.empty()) pse.push_back(-1);
            else pse.push_back(st.top()); 
            st.push(i);
        }
        return;
    }
    void nextsmall(vector<int>& heights, vector<int>& nse){
        stack<int> st;
        int n = heights.size();
        for(int i = heights.size()-1; i>=0 ;i--){
            int el = heights[i];
            while(!st.empty() && heights[st.top()] >= el) st.pop();
            if(st.empty()) nse.push_back(n);
            else nse.push_back(st.top());
            st.push(i);
        }
        return;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> pse,nse;
        prevsmall(heights,pse);
        nextsmall(heights,nse);
        long long val = 0;
        long long maxi = 0;
        int n = heights.size();
        for(int i=0; i<heights.size(); i++){
            val = 1LL*heights[i] * (nse[n-i-1] - pse[i] -1);
            maxi = max(maxi,val);
        }
        return (int)maxi;
    }
};