class Solution {
public:
    bool func(vector<vector<char>>& board, string word,int i,int row,int col){
        if(i == word.size()) return true;
        if(row < 0 || row>= board.size() || col<0 || col>= board[0].size()|| board[row][col] != word[i])   return false;
        char el = board[row][col];
        board[row][col] = '#';
        int u = func(board,word,i+1,row-1,col);
        int l = func(board,word,i+1,row,col-1);
        int r = func(board,word,i+1,row,col+1);
        int d = func(board,word,i+1,row+1,col);
        board[row][col] = el;
        return u||d||l||r;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(); int m = board[0].size();
        for(int i=0;i<n;i++)
            for(int j = 0;j<m;j++)
                if(func(board,word,0,i,j)) return true;

        return false;
    }
};