class Triplet{
    public:
    int row;
    int col;
    int time;
    Triplet(int i,int j, int t){
        row = i;
        col = j;
        time = t;
    }
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size(); int n = grid[0].size();
        queue<Triplet> que;
        int fresh = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                //push all rotten oranges into queue. all of them are ground zero. time zero.
                if(grid[i][j]==2) que.push({i,j,0});
                if(grid[i][j]==1) fresh++; // count all fresh oranges
                //cuz they are about to be infected and we need to verify
            }
        }
        int maxtime = 0;
        while(!que.empty()){
            Triplet t = que.front();
            int row = t.row; int col = t.col; int time = t.time;
            que.pop();
            maxtime = max(maxtime,time); //keeps track of time since infection started.

            //check where can we go.
            bool top = row==0? false : grid[row-1][col]==1;
            bool right = col==n-1? false: grid[row][col+1]==1;
            bool left = col==0? false: grid[row][col-1]==1;
            bool down = row==m-1? false : grid[row+1][col]==1;

            //if we can go - 
            if(top){
                grid[row-1][col]=2; //infect them niggas
                fresh--; // decrease count, cuz one nigga down.
                // this nigga gonna infect the rest, so we gonna push him into infected oranges queue.
                que.push({row-1,col,time+1}); 
            }
            if(down){
                grid[row+1][col]=2; fresh--;
                que.push({row+1,col,time+1});
            }
            if(left){
                grid[row][col-1]=2; fresh--;
                que.push({row,col-1,time+1});
            }
            if(right){
                grid[row][col+1]=2; fresh--;
                que.push({row,col+1,time+1});
            }
        }
        //checking if any good oranges left, or all infected.
        if(fresh>0) return -1; 
        return maxtime;
    }
};
