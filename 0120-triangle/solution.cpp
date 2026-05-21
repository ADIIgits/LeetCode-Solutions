class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle[triangle.size()-1].size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        dp[0][0]=triangle[0][0];
        for(int i=0;i<triangle.size();i++){
            for(int j=0;j<triangle[i].size();j++){
                if(i==0 && j==0) continue;
                int top = INT_MAX,topleft = INT_MAX;

                if(j<i) top = dp[i-1][j];
                if(j>0) topleft = dp[i-1][j-1];
                dp[i][j] = triangle[i][j] + min(top,topleft);
            }
        }
        int minel = INT_MAX;
        for(int el:dp[n-1]) minel = min(minel,el);
        return minel;
    }
};
