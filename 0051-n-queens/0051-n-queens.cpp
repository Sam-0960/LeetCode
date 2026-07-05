class Solution {
public:
    vector<vector<string>> ans;

    void func(int row, vector<string>& board, int n,vector<int>& upper_left,vector<int>& upper_right,vector<int>& horizontal){
        if(row == n){
            ans.push_back(board);
            return;
        }
        for(int col = 0 ; col<n ;col++){
            if(upper_left[row+col] == 0 && upper_right[n-1+row-col] == 0 && horizontal[col] == 0){
                upper_left[row+col] = 1;
                upper_right[n-1+row-col] = 1;
                horizontal[col] = 1;
                board[row][col] = 'Q';
                func(row+1,board,n,upper_left,upper_right,horizontal);
                board[row][col] = '.';
                upper_left[row+col] = 0;
                upper_right[n-1+row-col] = 0;
                horizontal[col] = 0;
            }
        }

    }
    vector<vector<string>> solveNQueens(int n) {
        string s;
        for(int i = 0 ; i < n ; i++) s.push_back('.');
        vector<string> board(n);
        for(int i=0;i<n;i++) board[i] = s;

        vector<int> upper_right(2*n-1);
        vector<int> upper_left(2*n-1);
        vector<int> horizontal(n);
        func(0,board, n, upper_right,upper_left,horizontal);

        return ans;
    }
};