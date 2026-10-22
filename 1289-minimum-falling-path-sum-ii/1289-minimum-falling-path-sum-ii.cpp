class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int best1 = INT_MAX, best2 = INT_MAX;
        int index = -1;
        for(int i=0; i<n; i++){
            if(best1 > grid[0][i]){
                best2 = best1;
                best1 = grid[0][i];
                index = i;
            } 
            else if(grid[0][i] < best2) best2 = grid[0][i];
        }

        for(int i=1; i<n; i++){
            for(int j =0; j<n; j++){
                if(j == index){
                    grid[i][j] += best2;
                }else grid[i][j] += best1;
            }
            best1 =INT_MAX, best2 = INT_MAX;
            for(int k=0; k<n; k++){
                if(best1 > grid[i][k]){
                    best2 = best1;
                    best1 = grid[i][k];
                    index = k;
                } 
                else if(grid[i][k] < best2) best2 = grid[i][k];
            }
        }
        return *min_element(grid[n-1].begin(), grid[n-1].end());
    }
};