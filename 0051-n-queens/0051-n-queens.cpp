class Solution {
public:
    bool caniplace(int row, int col,int n, vector<string>& board){
        int r , c;
        for(int i=0;i<row;i++){
            if(board[i][col] == 'Q') return false;
        }
        for(int i = 0; i<col ; i++){
            if(board[row][i] == 'Q') return false;
        }
        r = row, c = col;
        while(r<n && c<n && r>=0 && c>=0){
            if(board[r--][c++] == 'Q') return false;
        }
        r = row, c = col;
        while(r<n && c<n && r>=0 && c>=0){
            if(board[r--][c--] == 'Q') return false;
        }
        return true;
    }
    vector<vector<string>> ans;
    void f(int row,int n,vector<string>& board){
        if(row == n){
            ans.push_back(board);
            return;
        }else{
            for(auto col = 0; col<n; col++){
                if(caniplace(row,col,n,board)){
                    // add to the board and recurse next row
                    board[row][col] = 'Q';
                    f(row+1,n,board);
                    board[row][col] = '.';
                    // remove from the board
                }
            }
        }
    }  
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board;
        string s;
        for(auto x = 0; x<n; x++) s.push_back('.');
        for(auto x = 0; x<n; x++) board.push_back(s);
        int row  = 0;
        f(row,n,board);
        return ans;
    }
};