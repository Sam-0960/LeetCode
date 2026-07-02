class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int lo1 = 0, hi1 = rows-1;
        while(lo1 <= hi1){
            int mid1 = lo1 + (hi1-lo1)/2;
            int min_row = matrix[mid1][0], max_row =  matrix[mid1][cols-1];
            if(target >=  min_row && target <= max_row ){
                return binary_search(matrix[mid1].begin(), matrix[mid1].end(), target);

            }else if(target> max_row){
                lo1 = mid1+1;
            }else{
                hi1 = mid1-1;
            }
        }
        return false;
    }
};