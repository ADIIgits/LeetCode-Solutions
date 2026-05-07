class Solution {
public:
    void generate(int n,string s,vector<string> &ans){
        if(s.length()==n){
            ans.push_back(s);
            return;
        }
        // for(int i=0;i<n;i++){
        //     generate(n,s+'0',ans);
        //     generate(n,s+'1',ans);
        // }
        generate(n,s+'1',ans);
        if(s.empty() || s.back()!='0') generate(n,s+'0',ans);

    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        generate(n,"",ans);
        return ans;
    }
};
