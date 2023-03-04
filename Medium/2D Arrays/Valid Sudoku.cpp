class Solution {
public:

    bool checkRow(vector<vector<char>>& board , int row){
        set<char> s;
        for(int i=0;i<9;i++){
            if(s.find(board[row][i]) != s.end())
                return false;
            if(board[row][i] != '.')
                s.insert(board[row][i]);    
        }
        return true;
    }

    bool checkCol(vector<vector<char>>& board , int col){
        set<char> s;
        for(int i=0;i<9;i++){
            if(s.find(board[i][col]) != s.end())
                return false;
            if(board[i][col] != '.')
                s.insert(board[i][col]);    
        }
        return true;
    }

    bool checkBox(vector<vector<char>>& board , int row, int col){
        set<char> s;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int curr = board[i+row][j+col];
                if(s.find(curr) != s.end())
                    return false;
                if(curr != '.')
                    s.insert(curr);

            } 
        }
        return true;
    }

    bool isValid(vector<vector<char>>& board , int row, int col){
        return checkRow(board,row) && checkCol(board,col) &&
                checkBox(board , row-row%3 , col-col%3);
    }

    bool    isValidSudoku(vector<vector<char>>& board)
    {
        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){
                if(!isValid(board,row,col))
                    return false;
            }
        }
        return true;
    }
};
