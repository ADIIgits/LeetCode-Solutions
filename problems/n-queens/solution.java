class Solution {
    public static boolean isSafe(char[][] board,int row,int col){
        int n = board.length;
        if(board[row][col]=='Q') return false;
        //check row
        for(int i=0;i<n;i++){
            if(board[row][i]=='Q') return false;
        }
        //check col
        for(int i=0;i<n;i++){
            if(board[i][col]=='Q') return false;
        }
        int r,c;
        r=row;c=col;
        //check top left
        while(r>=0 && c>=0){
            if(board[r][c]=='Q') return false;
            r--;c--;
        }
        r=row;c=col;
        //check top right
        while(r>=0 && c<n){
            if(board[r][c]=='Q') return false;
            r--;c++;
        }
         r=row;c=col;
        //check bottom left
        while(r<n && c>=0){
            if(board[r][c]=='Q') return false;
            r++;c--;
        }
         r=row;c=col;
        //check bottom right
        while(r<n && c<n){
            if(board[r][c]=='Q') return false;
            r++;c++;
        }
        return true;

    }
    public static void nqeens(List<List<String>> ans,char[][] board,int row){
        int n = board.length;
        if(row==n){
            List<String> boardconfig = new ArrayList<>();
            for(int i=0;i<n;i++){
                String s = "";
                for(int j=0;j<n;j++){
                    s+=board[i][j];
                }
                boardconfig.add(s);
            }
            ans.add(boardconfig);
            return;
        }
        for(int j=0;j<n;j++){
            if(isSafe(board,row,j)){ //checking
                board[row][j]='Q'; // and placing
                nqeens(ans,board,row+1); //repeatedly. untill row = n.
                board[row][j]='.'; //undo the changes while returning
            }
        }
    }
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> ans = new ArrayList<>();
        char[][] board = new char[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                board[i][j]='.';
            }
        }
        nqeens(ans,board,0);
        return ans;
    }
}