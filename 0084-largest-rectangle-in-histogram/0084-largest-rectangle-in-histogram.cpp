class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxarea = 0;
        int pse =INT_MAX, nse = INT_MAX;
        stack<int> st;
        for(int i = 0 ; i<heights.size(); i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int el = heights[st.top()];
                st.pop();
                pse = st.empty() ? -1: st.top();
                nse = i;
                maxarea = max(maxarea , el*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            nse = heights.size();
            int el = heights[st.top()];
            st.pop();
            pse = st.empty() ? -1: st.top();
            maxarea = max(maxarea , el*(nse - pse-1));
        }
        return maxarea;
    }
};