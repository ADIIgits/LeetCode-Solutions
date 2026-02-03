class Solution {
    void generate(int n,vector<string> &ans,string s){
        if(s.length()==n){
            
                ans.push_back(s);
            
            return;
        }
        generate(n,ans,s+"1");
        if(s.empty() || s.back()!='0') generate(n,ans,s+"0");
        
    }
public:
    vector<string> validStrings(int n) {
        vector<char> vec;
        vector<string> ans;
        generate(n,ans,"");
        return ans;
    }
};