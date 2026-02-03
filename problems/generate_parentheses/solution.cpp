class Solution {
    void generate(int n,vector<string> &ans,string s,int open, int closed){
        if(s.length()==2*n){
            ans.push_back(s);
            return;
        }
        if(open<n) generate(n,ans,s+"(",open+1,closed);
        if(closed<open) generate(n,ans,s+")",open,closed+1);
    }
public:
    vector<string> generateParenthesis(int n) {
        string s;
        vector<string> ans;
        generate(n,ans,s,0,0);
        return ans;
    }
};