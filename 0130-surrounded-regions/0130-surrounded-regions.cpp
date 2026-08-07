class Solution {
public:
    void dfs(int row,int col,vector<vector<char>>& board){
        if(row < 0 || row >= board.size() || col < 0 ||col >=board[0].size() || board[row][col] == 'X' || board[row][col] == 'Z') return;
        board[row][col] = 'Z';
        dfs(row+1,col,board);
        dfs(row-1,col,board);
        dfs(row,col-1,board);
        dfs(row,col+1,board);
        return;
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int n = board.size();  int m = board[0].size();
        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O')
                dfs(0, i, board);
        }
        for (int i = 1; i < n - 1; i++) {
            if (board[i][0] == 'O')
                dfs(i, 0, board);
        }
        for (int i = 1; i < n - 1; i++) {
            if (board[i][m - 1] == 'O')
                dfs(i, m - 1, board);
        }
        for (int i = 0; i < m; i++) {
            if (board[n - 1][i] == 'O')
                dfs(n - 1, i, board);
        }

        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        for(int i = 0; i<n ; i++){
            for(int j = 0; j<m ;j++){
                if(board[i][j] == 'Z') board[i][j] = 'O';
            }
        }
        return ;
    }
};
