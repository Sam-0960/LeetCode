class Solution {
public:
    bool isSafe(int row, int col,vector<string>& board,int n){
        int duprow = row;
        int dupcol = col;
        while(duprow >= 0){
            if(board[duprow--][dupcol] == 'Q') return false;
        }
        duprow = row;
        dupcol = col;
        while(duprow >= 0 && dupcol >= 0){
            if(board[duprow--][dupcol--] == 'Q') return false;
        }
        duprow = row;
        dupcol = col;
        while(duprow >= 0 && dupcol < n){
            if(board[duprow--][dupcol++] == 'Q') return false;
        }
        return true;
    }
    void solve(int row, vector<string>& board, vector<vector<string>>& ans,int n ){
        if(row == n){
            ans.push_back(board);
            return;
        }
        for(int i = 0 ; i<n; i++){
            if(isSafe(row, i, board, n)){
                board[row][i] = 'Q';
                solve(row+1,board, ans,n);
                board[row][i] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string v;
        for(int i=0; i<n; i++) v.push_back('.');
        vector<string> board(n);

        for(int i=0 ; i<n; i++){
            board[i]= v;
        }

        solve(0,board, ans, n);
        return ans;
    }
};