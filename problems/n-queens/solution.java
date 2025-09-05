class Solution {
    public static boolean isSafe(char[][] board,int row,int col){
        int n = board.length;
        //no need to check row, cuz we are already traversing row wise,
        for(int i=0;i<n;i++){
            if(board[i][col]=='Q') return false;
        }

        int r = row; int c = col;
       
        //bottom-right
        while(r<n && c<n){
            if(board[r][c]=='Q') return false;
            r++;c++;
        }

        r=row;c=col;
        //bottom-left
        while(r<n && c>=0){
            if(board[r][c]=='Q') return false;
            r++;c--;
        }

        r=row;c=col;
        //upper-right
        while(r>=0 && c<n){
            if(board[r][c]=='Q') return false;
            r--;c++;
        }

        r=row;c=col;
        //upper-left
        while(r>=0 && c>=0){
            if(board[r][c]=='Q') return false;
            r--;c--;
        }

        return true;
        

    }
    public static void nqeen(char[][] board,List<List<String>> ans,int row){
        int n = board.length;
        if(row==n){
            List<String> list = new ArrayList<>();
            for(int i=0;i<n;i++){
                String s = "";
                for(int j=0;j<n;j++){
                    s+=board[i][j];
                }
                list.add(s);
            }
            ans.add(list);
            return;
        }

        for(int i=0;i<n;i++){
            if(isSafe(board,row,i)){
                board[row][i] = 'Q';
                nqeen(board,ans,row+1);
                board[row][i]= '.';
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
        nqeen(board,ans,0);
        return ans;
    }
}