class Solution {
    bool issafe(vector<vector<char>>& board,int row,int col,char num){
        int n = board.size();
        //check row
        for(int i=0;i<n;i++){
           if(board[row][i]==num) return false;
        }

        //check col
         for(int i=0;i<n;i++){
            if(board[i][col]==num) return false;
        }

        int r = row/3; int c=col/3;
        //check subbox
        for(int i=r*3;i<r*3 + 3;i++){
            for(int j=c*3;j<c*3 + 3;j++){
                if(board[i][j]==num) return false;
            }
        }
        return true;
    }
    bool checksudoku(vector<vector<char>>& board,int row,int col){
        int n = board.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='.') continue;
                char num = board[i][j];
                board[i][j]='.';
                if(!issafe(board,i,j,num)) return false;
                board[i][j]=num;
                // else return false;
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return checksudoku(board,0,0);
    }
};