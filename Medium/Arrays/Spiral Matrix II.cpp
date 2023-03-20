class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> arr(n,vector<int>(n));
        int curr=1, i=0, j=0, left= 0, right= n-1,top=0,bot= n-1;
        
        while(curr<= (n*n)){
            
            //left -> right
            while(curr<= (n*n) && j<= right) arr[i][j++]= curr++;
            j--, i++, top++;
            
            //top -> bottom
            while(curr<= (n*n) && i<= bot) arr[i++][j]= curr++;
            i--, j--, right--;
            
            //right -> left
            while(curr<= (n*n) && j>= left) arr[i][j--]= curr++;
            j++, i--, bot--;
            
            //bottom -> top
            while(curr<= (n*n) && i>= top) arr[i--][j]= curr++;
            i++, j++, left++;
        }
        
        return arr;
    }
};
