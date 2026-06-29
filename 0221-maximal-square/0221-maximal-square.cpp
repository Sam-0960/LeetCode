class Solution {
public:
    int Area_of_rect(vector<int>& arr){
        stack<int> st;
        int ans = 0;
        for(int i=0; i<arr.size(); i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                int el = arr[st.top()];
                st.pop();
                int nse = i;
                int pse = (st.empty())? -1: st.top();
                int width = nse - pse - 1;
                int side = min(el, width);
                ans = max(ans, side * side);
            }
            st.push(i);
        }
        while(!st.empty()){
            int el = arr[st.top()];
                st.pop();
                int nse = arr.size();
                int pse = (st.empty())? -1: st.top();
                int width = nse - pse - 1;
                int side = min(el, width);
                ans = max(ans, side * side);        
        }
        return ans;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size() ; int cols = matrix[0].size();
        int maxsq = 0;
        vector<int> hist(cols,0);
        for(int i = 0 ; i<rows; i++){
            for(int j = 0 ; j<cols ; j++){
                hist[j] = (matrix[i][j] == '1')? hist[j]+1 : 0;
            }
            int area = Area_of_rect(hist);
            maxsq = max(maxsq,area);
        }
        return maxsq;
    }
};