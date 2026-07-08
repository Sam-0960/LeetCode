class Solution {
public:
    bool canPlace(int row, int col, vector<vector<char>>& board,char num){
        for(int i=0; i<board.size();i++){
            if(board[row][i] == num) return false;
        }
        for(int j =0 ;j <board[0].size() ;j++){
            if(board[j][col] == num)  return false;
        }
        int rows = row;
        int cols = col;
        if(rows < 3) rows = 0;
        else if(row < 6) rows = 3;
        else   rows = 6;
        if(cols < 3) cols = 0;
        else if(col < 6) cols = 3;
        else cols = 6;

        for(int i = rows; i<rows+3;i++)
            for(int j = cols; j<cols+3 ; j++)
                if(board[i][j] == num)
                    return false;
        
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i =0 ; i<board.size(); i++){
            for(int j = 0 ; j<board[0].size(); j++){
                if(board[i][j] == '.'){
                    for(int k = '1'; k<= '9'; k++){
                        if(canPlace(i,j,board,k)){
                            board[i][j] = k;
                            if(solve(board)) return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        if(solve(board))    return;
    }
};