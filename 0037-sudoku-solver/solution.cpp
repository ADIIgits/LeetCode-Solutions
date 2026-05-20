class Solution {
public:
    vector<vector<char>> ans;
    void save(vector<vector<char>>& board){
        int n = board.size();
        for(int i=0;i<n;i++){
            vector<char> vec;
            for(int j=0;j<n;j++){
                vec.push_back(board[i][j]);
            }
            ans.push_back(vec);
        }
    }
    bool issafe(vector<vector<char>>& board,char number,int row,int col){
        int n = board.size();
        //check row
        for(int i=0;i<n;i++){
            if(board[row][i]==number) return false;
        }
        //check col
        for(int i=0;i<n;i++){
            if(board[i][col]==number) return false;
        }
        int r = row/3; int c = col/3;
        for(int i=r*3;i<r*3 + 3;i++){
            for(int j=c*3;j<c*3+3;j++){
                if(board[i][j]==number) return false;
            }
        }
        return true;
    }
    void sudoku(vector<vector<char>>& board,vector<vector<char>> &ans,int row,int col){
        int n = board.size();
        if(row==n){
            save(board);
            return;
        }
        if(board[row][col]!='.'){
            if(col==n-1) sudoku(board,ans,row+1,0);
            else sudoku(board,ans,row,col+1);
            return;
        }
        for(int i='1';i<='9';i++){
            if(issafe(board,i,row,col)){
                board[row][col]=i;
                if(col==n-1) sudoku(board,ans,row+1,0);
                else sudoku(board,ans,row,col+1);
                board[row][col]='.';
            }
        }
    }
    void solveSudoku(vector<vector<char>>& board) {
        
        sudoku(board,ans,0,0);
        board = ans;
    }
};
