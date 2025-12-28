class Solution {
    bool issafe(vector<string> matrix,int row,int col){
        int n = matrix.size();
        if(matrix[row][col]=='Q') return false;
        //check row
        for(int i=0;i<n;i++){
            if(matrix[row][i]=='Q') return false;
        } 
        //check col
        for(int i=0;i<n;i++){
            if(matrix[i][col]=='Q') return false;
        } 
        //check down-right 
        int r=row; int c=col;
        while(r<n && c<n)
        {
            if(matrix[r][c]=='Q') return false;
            r++;c++;
        }
        //check down-left
        r=row; c=col;
        while(r<n && c>=0)
        {
            if(matrix[r][c]=='Q') return false;
            r++;c--;
        }
        //check up-left
        r=row; c=col;
        while(r>=0 && c>=0)
        {
            if(matrix[r][c]=='Q') return false;
            r--;c--;
        }
        //check up-right
        r=row; c=col;
        while(r>=0 && c<n)
        {
            if(matrix[r][c]=='Q') return false;
            r--;c++;
        }
        return true;
    }
    void nqueens(vector<string> &matrix,vector<vector<string>> &configs,int row,int col){
        int n = matrix.size();
        if(row<0 || col<0) return;
        if(col>=n) return;
        if(row==n){
            configs.push_back(matrix);
            return;
        }
        for(int i=0;i<n;i++){
            if(issafe(matrix,row,i)){
                matrix[row][i]='Q';
                nqueens(matrix,configs,row+1,0);
                matrix[row][i]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> matrix;
        for(int i=0;i<n;i++){
            string s="";
            for(int j=0;j<n;j++) s+='.';
            matrix.push_back(s);
        }
        vector<vector<string>> configs;
        nqueens(matrix,configs,0,0);
        return configs;
    }
};