class Solution {
public:
    int area(vector<int>& arr){
        stack<int> st;
        int n = arr.size();
        int maxi = 0;
        for(int i = 0 ; i<n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                int el = arr[st.top()];
                st.pop();
                int nse = i;
                int pse = (st.empty())? -1: st.top();
                maxi = max(maxi, el*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int el = arr[st.top()];
            st.pop();
            int nse = n;
            int pse = (st.empty())? -1: st.top();
            maxi = max(maxi, el*(nse-pse-1));
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = 0;
        int rows = matrix.size(); int cols = matrix[0].size();
        vector<int> histogram(cols,0);
        for(int i = 0 ; i<rows; i++){
            for(int j=0;j<cols; j++){
                histogram[j] = (matrix[i][j] == '1')? histogram[j]+1 : 0;
            }
            maxArea = max(maxArea , area(histogram));
        }
        return maxArea;
    }
};