class Solution {
    bool dfs(vector<vector<int>>& grid, vector<vector<bool>> &visited,int row,int col,int t){
        int n = grid.size();
        if(row<0 || col<0 || row>=n || col>=n) return false;
        if(visited[row][col] || grid[row][col] > t) return false;

        if(row==n-1 && col==n-1) return true;
        visited[row][col] = true;

        return dfs(grid,visited,row-1,col,t) ||
                dfs(grid,visited,row,col+1,t) ||
                dfs(grid,visited,row,col-1,t) ||
                dfs(grid,visited,row+1,col,t);
    }
    bool isvalid(vector<vector<int>>& grid,int posmax){
        //posmax is possible max time a path can take
        int n = grid.size();
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        return dfs(grid,visited,0,0,posmax);

    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        //whats min max time a path can have? - minimum of grid.
        //whats max maxtime a path can have? - max of grid.
        int n = grid.size();
        int mintime = INT_MAX;

        int st = grid[0][0]; int ed = n*n-1;
        while(st<=ed){
            int mid = st + (ed-st)/2;
            if(isvalid(grid,mid)){
                mintime = mid;
                ed = mid-1;
            } else st = mid+1;
        }
        return mintime;
        
    }
};