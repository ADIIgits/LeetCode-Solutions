class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(); int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0] = grid[0][0]; //pathsum from cell 1 to cell 1 is cell 1
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) continue; //since we have already 0,0, we skip here.
                //if there is no top for a cell, take an absurd max value, 
                //cuz we gonna pick the minimum anyway
                int top = i>0 ? dp[i-1][j] : INT_MAX; 
                //same for 'no-left' case
                int left = j>0 ? dp[i][j-1] : INT_MAX;
                //add current weight and pick whichever path was smallest
                dp[i][j] = grid[i][j] + min(top,left);               
            }
        }
        return dp[m-1][n-1];
    }
};
