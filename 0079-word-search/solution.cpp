class Solution {
public:
    bool find(vector<vector<char>>& board,string &word,vector<vector<int>> &vis,int row,int col,int i){
        int m = board.size(); int n = board[0].size();
        if(i==word.size()) return true;
        if(row==m || row<0) return false;
        if(col==n || col<0) return false;
        if(vis[row][col]) return false;
        //explore
        if(board[row][col]==word[i]){
            vis[row][col] = 1;
            if(find(board,word,vis,row+1,col,i+1)) return true; //down
            if(find(board,word,vis,row,col+1,i+1)) return true;//right
            if(find(board,word,vis,row,col-1,i+1)) return true;//left
            if(find(board,word,vis,row-1,col,i+1)) return true;//up
            vis[row][col] = 0;
        }
        

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(); int n = board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0] && find(board,word,vis,i,j,0)) return true; 
            }
        }
        return false;
    }
};
