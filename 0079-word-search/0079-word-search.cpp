class Solution {
public:
    bool func(int row, int col,vector<vector<char>>& board, string word, int index){
        if(index == word.size()) return true;
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[index])  return false;
        char el = board[row][col];
        board[row][col] = '#';

        //go up
        bool up = func(row-1,col,board,word ,index+1);
        //go down
        bool down = func(row+1,col,board,word ,index+1);
        //go left
        bool left = func(row,col-1,board,word ,index+1);
        // go right
        bool right = func(row,col+1,board,word ,index+1);

        board[row][col] = el;
        return up||down||left||right;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;
        for(int i=0 ; i<board.size(); i++){
            for(int j = 0 ; j<board[0].size(); j++){
                if(func(i,j,board,word,0)) return true;
            }
        }
        return ans;
    }
};