class Solution {
public:
    bool frogjump(vector<int>& stones,unordered_map<int,int> &map,int jumplen,int frog_pos,vector<vector<int>> &dp){
        int n = stones.size();
        if(frog_pos==n-1) return dp[frog_pos][jumplen] = true;
        if(dp[frog_pos][jumplen]!=-1) return dp[frog_pos][jumplen];
        //frog can only jump k,k+1,k-1 steps from current the current stone.
        int kay = stones[frog_pos]+jumplen;
        int kaypone = stones[frog_pos]+jumplen+1;
        int kaymone = stones[frog_pos]+jumplen-1;
        //check if using any of 3 available jumps, we can land on any stone ahead?
        //is there a stone with same value as our calculated jump?
        if(map.count(kay)){
            if(frogjump(stones,map,jumplen,map[kay],dp)) return true;
        }
        // this precaution is just for an edge case. 
        if(!(frog_pos == 0 && jumplen == 1) && map.count(kaypone)){
            if(frogjump(stones,map,jumplen+1,map[kaypone],dp)) return true;
        }
        //i mean, we dont wanna jump backward right?
        if(jumplen > 1 && map.count(kaymone)){
            if(frogjump(stones,map,jumplen-1,map[kaymone],dp)) return true;
        }
        return dp[frog_pos][jumplen] = false;
    }
    bool canCross(vector<int>& stones) {
        //few things that are clear
        //you have to make 3 calls, for jumping k step forward, k+1 step forward, or k-1 step forward
        //its not always neccesary that currstone+k (or even k+1 or k-1) will be the immediate next stone, it could be few stones ahead as well. so you need a way to fetch index of soon-to-be stones.(maps !!)
        // state of reccursion depends on whats the frog's position and how much step forward he took step (k? k+1? or k-1?) (jumplen !!)
        int n = stones.size();
        int jumplen = 1; int frog_pos=0;
        unordered_map<int,int> map;
        for(int i=0;i<n;i++) map[stones[i]] = i;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return frogjump(stones,map,jumplen,frog_pos,dp);
    }
};
