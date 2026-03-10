class Solution {
    int findnextstone(vector<int>& stones,int i,int el){
        int n = stones.size();
        int st=i+1; int ed = n-1;
        while(st<=ed){
            int mid = st + (ed-st)/2;
            if(stones[mid]==el) return mid;
            else if(stones[mid]<el) st = mid+1;
            else ed=mid-1; 
        }
        return -1;
    }
    bool cross(vector<int>& stones,int i,int k,vector<vector<int>> &dp){
        int n = stones.size();
        if(i==n-1) return true;
        if(i==-1) return false;
        if(k<0) return false;
        if(dp[i][k]!=-1) return dp[i][k];
        int kminusone  = findnextstone(stones,i,stones[i]+k-1);
        int korg  = findnextstone(stones,i,stones[i]+k);
        int kplusone  = findnextstone(stones,i,stones[i]+k+1);

        bool minus1 = cross(stones,kminusone,k-1,dp);
        bool none = cross(stones,korg,k,dp);
        bool plus1 = cross(stones,kplusone,k+1,dp);

        if(minus1 || none || plus1) dp[i][k]=1;
        else dp[i][k]=0;

        return dp[i][k];
    }
public:
    bool canCross(vector<int>& stones) {
        //base case when it reaches last stone, return true
        // k = stones[i-1]
        int n = stones.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return cross(stones,0,0,dp);
    }
};