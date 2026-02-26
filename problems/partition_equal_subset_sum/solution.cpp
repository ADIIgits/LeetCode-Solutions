class Solution {
    bool partition(vector<int>& nums,vector<vector<int>> &dp,int sum,int sumo,int i){
        if(i<0) return false;
        if(sum==sumo/2) return true;
        if(dp[i][sum]!=-1) return dp[i][sum]; 
        bool p1 = partition(nums,dp,sum+nums[i],sumo,i-1);
        bool p2 = partition(nums,dp,sum,sumo,i-1);
        return dp[i][sum] = p1 || p2;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sumo=0;
        for(int el:nums) sumo+=el;
        vector<vector<int>> dp(n,vector<int>(sumo,-1));
        if(sumo%2==0) return partition(nums,dp,0,sumo,n-1);
        else return false;
        
    }
};