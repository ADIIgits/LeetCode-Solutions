class Solution {
    public static boolean isValid(char[][] board,int row,int col){
        int n = board.length;
        //check col
        for(int i=0;i<n;i++){
            if(i!=row && board[i][col]==board[row][col]) return false;
        } 
        //check row
        for(int i=0;i<n;i++){
            if(i!=col && board[row][i]==board[row][col]) return false;
        } 
        //check 3x3 mat
        int r = row/3; int c=col/3;
        int sr = r*3; int er = (r*3) + 3;
        int sc = c*3; int ec = (c*3) + 3;
        for(int i=sr;i<er;i++){
            for(int j=sc;j<ec;j++){
                if(i!=row && j!=col && board[i][j]==board[row][col]) return false;
            }
        }
        return true;
    }
    public static boolean validSudoku(char[][] board,int row,int col){
        int n = board.length;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                // char num = board[i][j];
                // board[i][j]='.';
                if(board[i][j]!='.' && !isValid(board,i,j)) return false;
                // board[i][j]=num;
            }
        }
        return true;
          
    }
    public boolean isValidSudoku(char[][] board) {
        return validSudoku(board,0,0);
    }
}