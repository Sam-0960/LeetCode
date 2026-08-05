class Solution {
public:
    void f(int r, int c,vector<vector<char>>& grid){
        int rows = grid.size(); int cols = grid[0].size();
        int i = r , j = c;
        while(j<cols-1){
            if(grid[i][j+1] == 'X') { j++;grid[i][j] = '.';}
            else break;
        }
        while(i<rows-1){
            if(grid[i+1][j] == 'X') { i++;grid[i][j] = '.';}
            else break;
        }
        return;
    }
    int countBattleships(vector<vector<char>>& board) {
        int rows = board.size(); int cols = board[0].size();
        int ans = 0;
        for(int i =0 ; i<rows; i++){
            for(int j =0; j<cols ;j++){
                if(board[i][j] == 'X'){
                    ++ans;
                    f(i,j,board);
                }
            }
        }
        return ans;
    }
};