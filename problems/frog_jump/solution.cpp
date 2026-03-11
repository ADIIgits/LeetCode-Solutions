class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int,unordered_set<int>> dp;
        for(int s:stones) dp[s]={};
        dp[0].insert(0);
        for(int s:stones){
            for(int k:dp[s]){
                for(int jump=k-1;jump<=k+1;jump++){
                    if(jump>0 && dp.count(s+jump)) dp[s+jump].insert(jump);
                }
            }
        }
        return !dp[stones.back()].empty();
    }
};