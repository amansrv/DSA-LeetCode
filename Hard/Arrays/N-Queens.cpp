/*

    Time Complexity : O(N!), Where N is the size of chess board. For the first row, we check N columns; for the
    second row, we check the N - 1 column and so on. Hence, the time complexity will be N * (N-1) * (N-2) …. i.e.
    O(N!).
    
    Space Complexity : O(N^2), Vector of string(nQueens) space. Extra space is allocated for the vector of vector
    string(output), however the output does not count towards the space complexity.

    Solved using Array + Backtracking.

*/

class Solution {
private: 
    bool isSafePlace(int n, vector<string>& nQueens, int row, int col){
        for(int i=0; i<n; i++){
            if(nQueens[i][col] == 'Q'){
                return false;
            }
        }
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
            if(nQueens[i][j] == 'Q'){
                return false;
            }
        }
        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++){
            if(nQueens[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void solveNQueens(int n, vector<vector<string>>& output, vector<string>& nQueens, int row){
        if(row == n){
            output.push_back(nQueens);
            return;
        }
        for(int col=0; col<n; col++){
            if(isSafePlace(n, nQueens, row, col)){
                nQueens[row][col] = 'Q';
                solveNQueens(n, output, nQueens, row+1);
                nQueens[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> output;
        vector<string> nQueens(n , string(n, '.'));
        solveNQueens(n, output, nQueens, 0);
        return output;
    }
};
