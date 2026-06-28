class Solution {
public:
    long long max_rect_area(vector<int>& arr){
        long long maxi = 0;
        stack<int> st;
        for(int i = 0; i <arr.size(); i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                long long el = arr[st.top()];
                st.pop();
                long long nse = i;
                long long pse = (st.empty())? -1:st.top();
                maxi = max(maxi,(el*(nse-pse-1)));
            }
            st.push(i);
        }
        while(!st.empty()){
            long long el = arr[st.top()];
            st.pop();
            long long nse = arr.size();
            long long pse = (st.empty())? -1:st.top();
            maxi = max(maxi,(el*(nse-pse-1)));
        }
        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        long long maxarea = 0;
        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> hist(cols, 0);
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                hist[j] = (matrix[i][j] == '1') ? hist[j] + 1 : 0;
            }
            maxarea = max(maxarea, max_rect_area(hist));
        }
        return (int)maxarea;
    }

};