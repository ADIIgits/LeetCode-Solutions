class Solution {
    bool findword(vector<vector<char>>& board, string word, vector<vector<bool>> &isvisited,int idx,int row,int col){
        int m = board.size(); int n = board[0].size();
        int k = word.length();
        if(row<0 || col<0) return false;
        if(row>=m || col>=n) return false;
        if(isvisited[row][col]) return false;
        if(board[row][col]!=word[idx]) return false;
        if(idx==k-1) return true;
        isvisited[row][col]=true;
        bool found = findword(board,word,isvisited,idx+1,row-1,col) 
        || findword(board,word,isvisited,idx+1,row,col+1)
        || findword(board,word,isvisited,idx+1,row+1,col)
        || findword(board,word,isvisited,idx+1,row,col-1);
        isvisited[row][col]=false;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        //keep isvisited, gotta make 4 calls, up down left right
        //keep a string that tracks the path/sequenceofletters
        //if they match, booyah, return true;
        int m = board.size(); int n = board[0].size();
        vector<vector<bool>> isvisited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(findword(board,word,isvisited,0,i,j)) return true;
            }
        }
        return false;
    }
};