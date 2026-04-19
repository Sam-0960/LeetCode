class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v(rowIndex+1,0);
        for(int i = 0 ; i<rowIndex+1;i++){
            v[0] = 1;
            for( int j = min(i,rowIndex); j>= 1 ; j--){
                v[j] = v[j] + v[j-1];
            }
        }
        return v;
    } 
};