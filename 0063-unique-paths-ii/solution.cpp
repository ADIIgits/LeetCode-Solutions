class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(); int n = obstacleGrid[0].size(); 
        vector<vector<int>> dp(m,vector<int>(n,0));
        //you may ask why are we not populating first coln and first row as 1? 
        //well, we fill em dynamically.
        dp[0][0] = 1; //1 way to reach start from start.
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j] = 0;
                    continue;
                }
                if(i>0) dp[i][j] += dp[i-1][j]; //if dp[1][0] gets filled with 1 cuz +=dp[0][0];
                if(j>0) dp[i][j] += dp[i][j-1]; //if dp[0][1] gets filled with 1 cuz, +=dp[0][0];
            }
        }
        return dp[m-1][n-1];
    }
};
