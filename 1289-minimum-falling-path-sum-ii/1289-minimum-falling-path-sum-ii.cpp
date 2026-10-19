class Solution {
public:
    int findMin(vector<vector<int>>& grid,int i,int j){
        int mini = INT_MAX;int n = grid.size();
        for(int k = 0 ; k<n ;k++){
            if( k == j ) continue;
            mini = min(mini , grid[i][k]);
        }
        return mini;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i = 1;i<n;i++){
            for(int j =0; j<n; j++){
                int el = findMin(grid,i-1,j);
                grid[i][j] += el;
            }
        }
        return *min_element(grid[n-1].begin(), grid[n-1].end());
    }
};