class Solution {
public:
    bool check(vector<vector<char>>& board, int row, int col, char c)
    {
        for(int i = 0; i < 9; i++) 
            if(board[i][col] == c) 
                return false;

        for(int i = 0; i < 9; i++) 
            if(board[row][i] == c) 
                return false;

        int x0 = (row/3) * 3, y0 = (col/3) * 3;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[x0 + i][y0 + j] == c) return false;
            }
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board, int r, int c)
    {
        if(r==9)
        return true;
        if(c==9)
        return solve(board, r+1, 0);
        if(board[r][c]!='.')
        return solve(board, r, c+1);
        for(char i='1';i<='9';i++)
        {
            if(check(board, r, c, i))
            {
                board[r][c]=i;
                if(solve(board, r, c+1))
                return true;
                board[r][c]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};
