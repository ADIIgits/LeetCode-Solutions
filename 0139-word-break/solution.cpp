class Solution {
public:
    // unordered_map<int,bool> dp;
    
    bool wordbreak(string &s,unordered_set<string> &dict,vector<int> &dp,int start){
        int n = s.length();
        if(start==n) return true;
        if(dp[start]!=-1) return dp[start];
        for(int i=start;i<n;i++){
            string firsthalf = s.substr(start,i - start + 1);
            if(dict.contains(firsthalf)){
                if(wordbreak(s,dict,dp,i+1)) return dp[start] = 1;
            }
        }
        return dp[start] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        unordered_set<string> dict;
        vector<int> dp(n,-1);
        // dp.resize(n,-1);
        for(string word:wordDict) dict.insert(word);
        return wordbreak(s,dict,dp,0);
    }
};
