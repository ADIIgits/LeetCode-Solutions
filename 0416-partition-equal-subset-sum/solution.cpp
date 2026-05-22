class Solution {
public:
    bool partition(vector<int>& nums,int suma,int sumb,int i,vector<vector<int>> &dp){
        int n = nums.size();
        if(i==n) return false;
        if(suma==sumb/2) return true;
        if(suma > sumb/2) return false;
        if(dp[suma][i]!=-1) return dp[suma][i]==1;
        bool take = partition(nums,suma+nums[i],sumb,i+1,dp);
        bool pass = partition(nums,suma,sumb,i+1,dp);
        return dp[suma][i] = take || pass;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int el:nums) sum+=el;
        vector<vector<int>> dp(sum+1,vector<int>(n,-1));
        if(sum%2==0) return partition(nums,0,sum,0,dp);
        else return false;
    }
};
