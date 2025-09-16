class Solution {
    public static boolean isPlaceable(char[][] board,int row,int col,char num){
        int n = board.length;
        //check row
        for(int i=0;i<n;i++){
            if(board[i][col]==num) return false;
        }
        //check col
        for(int i=0;i<n;i++){
            if(board[row][i]==num) return false;
        }
        int sr=(row/3)*3;
        int er=sr+3;
        int sc=(col/3)*3;
        int ec=sc+3;
        //check 3x3 mat
        for(int i=sr;i<er;i++){
            for(int j=sc;j<ec;j++){
                if(board[i][j]==num) return false;
            }
        }
        return true;
    }
    static int check=0;
    public static void sudoku(char[][] board,int row,int col){
        
        int n = board.length;
        if(row==n){
            check=1;
            return;
        }
        if(board[row][col]!='.'){
            if(col<n-1) sudoku(board,row,col+1);
            else sudoku(board,row+1,0);
        }
        else{
            for(char i='1';i<='9';i++){
                if(isPlaceable(board,row,col,i)){
                    board[row][col]=i;
                    if(col<n-1) sudoku(board,row,col+1);
                    else sudoku(board,row+1,0);
                    if(check==1) return;
                    board[row][col]='.';
                }
            }
        }  
        
        
        
    }
    public void solveSudoku(char[][] board) {
        sudoku(board,0,0);
        check=0;
    }
}