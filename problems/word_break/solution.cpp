class Solution {
    bool found(string s, unordered_set<string> &set){
        // return find(wordDict.begin(),wordDict.end(),s)!=wordDict.end();
        return set.count(s);
    }
    bool wordbreak(string s,unordered_set<string> &set,int i,vector<int> &dp){
        int n = s.length();
        if(i==n) return true;
        if(dp[i]!=-1) return dp[i];
        for(int j=i;j<n;j++){
            if(found(s.substr(i,j-i+1),set)){
                if(wordbreak(s,set,j+1,dp)) return dp[i]=1;
            }
        }
        return dp[i] = 0;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<int> dp(n,-1);
        unordered_set<string> set(wordDict.begin(),wordDict.end());
        return wordbreak(s,set,0,dp);
    }
};