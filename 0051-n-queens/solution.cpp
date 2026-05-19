class Solution {
public:
    bool issafe(vector<string> &board,int row,int col){
        int n = board.size();
        int r = row; int c = col;
        //check row
        for(int i=0;i<c;i++){
            if(board[row][i]=='Q') return false;
        }
        //check col
        for(int i=0;i<r;i++){
            if(board[i][col]=='Q') return false;
        }
        //up right
        r = row; c = col;
        while(r>=0 && c<n){
            if(board[r][c]=='Q') return false;
            r--;c++;
        }
        //up left
        r = row; c = col;
        while(r>=0 && c>=0){
            if(board[r][c]=='Q') return false;
            r--;c--;
        }
        
        return true;
    }
    void nqueens(vector<string> &board,vector<vector<string>> &ans,int row,int col){
        int n = board.size();
        if(row==n){
            ans.push_back(board);
            return;
        }
        if(board[row][col]=='Q') return;
        for(int j=0;j<n;j++){
            if(issafe(board,row,j)){
                board[row][j]='Q';
                nqueens(board,ans,row+1,0);
                board[row][j]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board;
        
        for(int i=0;i<n;i++){
            string str = "";
            for(int j=0;j<n;j++) str+='.';
            board.push_back(str);
        }
        nqueens(board,ans,0,0);
        return ans;
    }
};
