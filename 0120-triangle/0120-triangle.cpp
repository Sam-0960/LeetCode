class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for(int i=1; i<n; i++){
            int size = triangle[i].size();
            for(int j =0; j<size; j++){
                if(j == 0) triangle[i][j] += triangle[i-1][j];
                else if(j == size-1) triangle[i][j] += triangle[i-1][j-1];
                else{
                    int small = min(triangle[i-1][j],triangle[i-1][j-1]);
                    triangle[i][j] += small;
                }
            }
        }
        return *min_element(triangle[n-1].begin(),triangle[n-1].end());
    }
};