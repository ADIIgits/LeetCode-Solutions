class Solution {
    int maxloot(vector<int>& nums,vector<int> &dp,int i,int m){
        int n = nums.size();
        // if(i>=n) return 0;
        if(i>=m) return 0;
        if(dp[i]!=-1) return dp[i];
        int take = nums[i] + maxloot(nums,dp,i+2,m);
        int pass = maxloot(nums,dp,i+1,m);

        return dp[i] = max(take,pass);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n,-1);
        int first =  maxloot(nums,dp,0,n-1);
        for(int i=0;i<n;i++) dp[i]=-1;
        int last =  maxloot(nums,dp,1,n);
        return max(first,last);
    }
};