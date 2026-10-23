class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(); int n = matrix[0].size();
        for(int i = 1; i<m ; i++){
            for(int j = 1; j<n ; j++){
                matrix[i][j] = (matrix[i][j] == 1) ? min(matrix[i-1][j-1], min(matrix[i-1][j],matrix[i][j-1])) +1 : 0;
            }
        }
        int sum = 0;
        for(auto x: matrix)
            for(auto y: x)
                sum += y;
        return sum;
    }
};