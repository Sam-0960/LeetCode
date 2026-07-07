class Solution {
public:
    bool caniplace(vector<vector<char>>& board, int row, int col, int num){
        for(int i = 0 ; i< board.size() ; i++)  if(board[row][i] == num) return false;
        for(int i = 0; i<board.size(); i++) if(board[i][col] == num) return false;
        int r = row;
        int c = col;
        if(row < 3) r = 0;
        else if(row< 6) r =3;
        else r = 6;
        if(col < 3) c = 0;
        else if(col < 6) c = 3;
        else c = 6;
        for(int i = r ;i<r+3; i++)
            for(int j = c ; j <c+3; j++)
                if(board[i][j] == num) return false;
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i = 0 ; i<board.size();i++){
            for(int j= 0 ; j < board[0].size(); j++){
                if(board[i][j] == '.'){
                    for(int num = '1'; num <= '9'; num++){
                        if(caniplace(board,i,j,num)){
                            board[i][j] = num;
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
        if(solve(board)) return;
    }
};