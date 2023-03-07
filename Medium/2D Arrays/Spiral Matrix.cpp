class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top=0,bottom=matrix.size()-1,right=matrix[0].size()-1,left=0,direction=0;
        vector<int>res;
        while(top<=bottom and left<=right)
        {
            if(direction==0){

                for(int i=left;i<=right;i++)
                res.push_back(matrix[top][i]);
                top++;
            }
            else if(direction==1){

                for(int i=top;i<=bottom;i++)
                res.push_back(matrix[i][right]);
                right--;
            }
            else if(direction==2){

                for(int i=right;i>=left;i--)
                res.push_back(matrix[bottom][i]);
                bottom--;
            }
            else if(direction==3){

                for(int i=bottom;i>=top;i--)
                res.push_back(matrix[i][left]);
                left++;
            }
            direction=(direction+1)%4;
        }
        return res;
    }
};
