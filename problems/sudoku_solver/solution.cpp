class Solution {
    vector<vector<char>> newboard;
    void save(vector<vector<char>>& board){
        int n = board.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                newboard[i][j]=board[i][j];
            }
        }
    }
    bool issafe(vector<vector<char>>& board,int row,int col, char ch){
        int n = board.size();
        if(board[row][col]==ch) return false;
        for(int i=0;i<n;i++){
            if(board[row][i]==ch) return false; 
        }
        for(int i=0;i<n;i++){
            if(board[i][col]==ch) return false; 
        }
        int r = row/3; int c = col/3;
        for(int i=r*3;i<r*3 + 3;i++){
            for(int j=c*3;j<c*3 + 3;j++){
                if(board[i][j]==ch) return false; 
            }
        }
        return true;
    }
    void sudoku(vector<vector<char>>& board,int row,int col){
        int n = board.size();
        if(row==n){
            save(board);
            return;
        }
        if(board[row][col]!='.'){
            if(col<n-1) sudoku(board,row,col+1);
            else sudoku(board,row+1,0);
            return;
        }
        for(char ch='1';ch<='9';ch++){
            if(issafe(board,row,col,ch)){
                board[row][col]=ch;
                if(col<n-1) sudoku(board,row,col+1);
                else sudoku(board,row+1,0);
                board[row][col]='.';
            }
        }
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        for(int i=0;i<n;i++){
            vector<char> vec;
            for(int j=0;j<n;j++) vec.push_back('.');
            newboard.push_back(vec);
        }

        sudoku(board,0,0);
        
        board = newboard;
    }
};