class Solution {
    int maxloot(vector<int>& nums,vector<int> &dp,int i){
        int n = nums.size();
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int take = nums[i] + maxloot(nums,dp,i+2);
        int pass = maxloot(nums,dp,i+1);
        return dp[i] = max(take,pass);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return maxloot(nums,dp,0);
    }
};