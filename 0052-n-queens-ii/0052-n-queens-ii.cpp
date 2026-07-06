class Solution {
public:
    int ans = 0;
    void func(int row,vector<string>& board,int n,vector<int>& cols,vector<int>& upperleft,vector<int>& upperright ){
        if(row == n){
            ans++;
            return;
        }
        for(int col = 0 ;col<n;col++){
            if(cols[col] != 1 && upperleft[n-1+row-col] != 1 && upperright[row+col]!=1){
                board[row][col] = 'Q';
                cols[col] = 1;
                upperleft[n-1+row-col] = 1 ;
                upperright[row+col] = 1;
                func(row+1,board,n,cols,upperleft,upperright);
                cols[col] = 0;
                upperleft[n-1+row-col] = 0;
                upperright[row+col] = 0;
                board[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        string s;
        for(int i = 0 ; i<n;i++) s.push_back('.');
        vector<string> board;
        for(int i = 0 ; i<n; i++){
            board.push_back(s);
        }
        vector<int> cols(n);
        vector<int> upperleft(2*n-1);
        vector<int> upperright(2*n-1);
        func(0,board,n,cols,upperleft,upperright);
        return ans;
    }
};