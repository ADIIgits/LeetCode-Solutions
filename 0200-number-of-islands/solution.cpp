class Solution {
    void bfs(vector<vector<char>>& grid,vector<vector<bool>>& visited,int row,int col){
        int m = grid.size(); int n = grid[0].size();
        queue<pair<int,int>> que;
        que.push({row,col});
        visited[row][col]=true;
        while(!que.empty()){
            auto [r,c] = que.front();
            que.pop();
            //right;
            if(c<n-1 && !visited[r][c+1] && grid[r][c+1]=='1'){
                visited[r][c+1]=true;
                que.push({r,c+1});
            }
            //left;
            if(c>0 && !visited[r][c-1] && grid[r][c-1]=='1'){
                visited[r][c-1]=true;
                que.push({r,c-1});
            }
            //up;
            if(r>0 && !visited[r-1][c] && grid[r-1][c]=='1'){
                visited[r-1][c]=true;
                que.push({r-1,c});
            }
            //down;
            if(r<m-1 && !visited[r+1][c] && grid[r+1][c]=='1'){
                visited[r+1][c]=true;
                que.push({r+1,c});
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(); int n = grid[0].size();
        int island = 0;
        vector<vector<bool>> visited(m,vector<bool>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    bfs(grid,visited,i,j);
                    island++;
                }
            }
        }
        return island;
    }
};
