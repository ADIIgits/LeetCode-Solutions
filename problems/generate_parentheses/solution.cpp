class Solution {
    void generate(vector<string> &ans,string s,int left,int right,int n){
        if(s.length()==n*2){
            ans.push_back(s);
            return;
        }
        if(left<n) generate(ans,s+"(",left+1,right,n);
        if(right<left) generate(ans,s+")",left,right+1,n);
        
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(ans,"",0,0,n);
        return ans;
    }
};