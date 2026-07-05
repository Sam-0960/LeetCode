class Solution {
public:
    bool search_from_here(int row, int col,vector<vector<char>>& board, string word, int index){
        if(index == word.size())  return true;
        if(row < 0 || row == board.size() || col < 0 || col == board[0].size() || board[row][col] != word[index] ) return false;
        char ch = board[row][col];
        board[row][col] = '#';
        bool op1 = search_from_here(row+1,col,board,word, index+1);
        bool op2 = search_from_here(row,col+1,board,word, index+1);
        bool op3 = search_from_here(row-1,col,board,word, index+1);
        bool op4 = search_from_here(row,col-1,board,word, index+1);
        board[row][col] = ch;

        return op1 || op2 || op3 || op4;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i<board.size(); i++){
            for(int j = 0 ; j< board[0].size(); j++){
                if(search_from_here(i,j,board,word,0)) return true;
            }
        }
        return false;
    }
};