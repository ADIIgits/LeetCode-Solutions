class Solution {
    void generate(vector<string> &parens,int n,string str,int open,int close){
        if(str.length()==n*2){
            parens.push_back(str);
            return;
        }
        if(open==n+1 || close==n+1) return;
        if(open<n)
        generate(parens,n,str+"(",open+1,close);
        if(close<open)
        generate(parens,n,str+")",open,close+1);
        
        
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> parens;
        generate(parens,n,"",0,0); 
        return parens;
    }
};