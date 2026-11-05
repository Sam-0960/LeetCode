class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int best1 = INT_MAX, best2 = INT_MAX;
        int indx = -1;
        for(int i = 0 ; i< n ; i++){
            if(grid[0][i] < best1){
                best2 = best1;
                best1 = grid[0][i];
                indx = i;
            }
            else if(grid[0][i] < best2){
                best2 = grid[0][i];
            }
        }
        for(int i=1; i<n ; i++){
            for(int j = 0; j<n ; j++){
                if(j == indx){
                    grid[i][j] += best2;
                }else grid[i][j] += best1;
            }
            best1 = INT_MAX; best2 = INT_MAX;indx = -1;
            for(int j = 0 ; j<n ; j++){
                if(grid[i][j] < best1){
                    best2 = best1;
                    best1 = grid[i][j];
                    indx = j;
                }
                else if(grid[i][j] < best2){
                    best2 = grid[i][j];
                }
            }
        }

        return *min_element(grid[n-1].begin(),grid[n-1].end());
    }
};