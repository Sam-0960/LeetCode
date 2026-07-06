class Solution {
public:
    bool canPlace(vector<vector<char>>& board,int row, int col,int num){
        for(int i = 0 ; i<board.size(); i++){
            if(board[i][col] == num) return false;
        }
        for(int i = 0 ; i<board[0].size(); i++){
            if(board[row][i] == num) return false;
        }
        
        int grid_row = -1;
        if(row>=0 && row <3) grid_row = 0;
        else if(row>= 3 && row < 6) grid_row = 3;
        else grid_row = 6;
        int grid_col = -1;
        if(col>=0 && col <3) grid_col = 0;
        else if(col>= 3 && col < 6) grid_col = 3;
        else grid_col = 6;

        for(int i = grid_row ; i<3+grid_row; i++)
            for(int j = grid_col; j<3+grid_col;j++)
                if(board[i][j] == num)  return false;
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') {
                    for (int num = 1; num <= 9; num++) {
                        if (canPlace(board, i, j, (num + '0'))) {
                            board[i][j] = num + '0';
                            if(solve(board)) return true;
                            else{
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        if (solve(board))   return;
    }
};