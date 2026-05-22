class Solution {
public:
    int pickcherry(vector<vector<int>>& grid,int i,int a,int b,vector<vector<vector<int>>> &dp){
        int n = grid.size(); int m = grid[0].size();
        if(i==n){
            return 0;
        }
        if(a < 0 || a >= m || b < 0 || b >= m) return -1e8;
        if(dp[i][a][b]!=-1) return dp[i][a][b];
        int maxi = -1e8;
        for(int j=-1;j<=1;j++){
            maxi = max(maxi,pickcherry(grid,i+1,a-1,b+j,dp));
        }
        for(int j=-1;j<=1;j++){
            maxi = max(maxi,pickcherry(grid,i+1,a,b+j,dp));
        }
        for(int j=-1;j<=1;j++){
            maxi = max(maxi,pickcherry(grid,i+1,a+1,b+j,dp));
        }
        return dp[i][a][b] = a==b ? grid[i][a] + maxi : grid[i][a] + grid[i][b] + maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        // dp[i][j][k] = mat[i][j] + mat[ri][rj];
        
        int n = grid.size(); int m = grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return pickcherry(grid,0,0,m-1,dp);
    }
};
