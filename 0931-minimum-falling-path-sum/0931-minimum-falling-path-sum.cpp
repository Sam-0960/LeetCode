class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 1; i< n ; i++){
            for(int j= 0 ; j <n ; j++){
                int el = matrix[i-1][j];
                if(j-1 >=0){
                    el = min(el,matrix[i-1][j-1]);
                }
                if(j+1 < n){
                    el = min(el,matrix[i-1][j+1]);
                }
                matrix[i][j] += el;
            }
        }
        return *min_element(matrix[n-1].begin(),matrix[n-1].end());
    }
};