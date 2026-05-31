class Solution {
public:
    void BFS(vector<vector<char>>& grid,vector<vector<bool>> &vis,int source_row,int source_col){
        int n = grid.size(); int m = grid[0].size();
        queue<pair<int,int>> que;
        que.push({source_row,source_col});
        vis[source_row][source_col] = true;
        while(!que.empty()){
            auto [row,col] = que.front();
            que.pop();
            //down
            int r = row+1; int c = col;
            if(r<n && grid[r][c]=='1' && !vis[r][c]){
                vis[r][c] = true;
                que.push({r,c});
            }
            //up
            r = row-1; c = col;
            if(r >=0 && grid[r][c]=='1' && !vis[r][c]){
                vis[r][c] = true;
                que.push({r,c});
            }
            //left
            r = row; c = col-1;
            if(c >= 0 && grid[r][c]=='1' && !vis[r][c]){
                vis[r][c] = true;
                que.push({r,c});
            }
            //right
            r = row; c = col+1;
            if(c<m && grid[r][c]=='1' && !vis[r][c]){
                vis[r][c] = true;
                que.push({r,c});
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int n = grid.size(); int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    count++;
                    BFS(grid,vis,i,j);
                }
            }
        }
        return count;
    }
};
