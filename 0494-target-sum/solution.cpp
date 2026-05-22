class Solution {
public:
    int count = 0;
    int find(vector<int>& nums, int target,int sum,int i,vector<vector<int>> &dp,int offset){
        int n = nums.size();
        if(i==n){
            return sum==target ? 1 : 0;
        }
        if(dp[i][sum+offset]!=-1) return dp[i][sum+offset];
        return dp[i][sum+offset] = find(nums,target,sum+nums[i],i+1,dp,offset) + find(nums,target,sum-nums[i],i+1,dp,offset);
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int el:nums) sum+=el;
        vector<vector<int>> dp(n,vector<int>(2*sum+1,-1));
        return find(nums,target,0,0,dp,sum);
    }
};
