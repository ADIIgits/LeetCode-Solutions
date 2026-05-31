class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(); int n = grid[0].size();
        int maxminute = 0;
        int fresh = 0;
        queue<vector<int>> que;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) fresh++;
                if(grid[i][j]==2) que.push({i,j,0});
            }
        }
        while(!que.empty()){
            vector<int> currnode = que.front();
            que.pop();
            int row = currnode[0];
            int col = currnode[1];
            int level = currnode[2];
            //down
            int r = row+1; int c = col;
            if(r < m && grid[r][c]==1){
                que.push({r,c,level+1});
                grid[r][c] = 2;
                fresh--;
            }
            //up
            r = row-1; c = col;
            if(r >= 0 && grid[r][c]==1){
                que.push({r,c,level+1});
                grid[r][c] = 2;
                fresh--;
            }
            //left
            r = row; c = col-1;
            if(c >= 0 && grid[r][c]==1){
                que.push({r,c,level+1});
                grid[r][c] = 2;
                fresh--;
            }
            //right
            r = row; c = col+1;
            if(c < n && grid[r][c]==1){
                que.push({r,c,level+1});
                grid[r][c] = 2;
                fresh--;
            }
            maxminute = max(maxminute,level);
        }
        if(fresh > 0) return -1;
        return maxminute;
    }
};
