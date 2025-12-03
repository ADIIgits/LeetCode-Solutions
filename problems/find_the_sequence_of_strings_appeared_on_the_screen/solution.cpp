class Solution {
    void generate(string target, vector<string> &ans,string &str,int i){
        int n = target.length();
        if(i==n){
            return;
        }

        str.push_back('a');
        ans.push_back(str);
        while(str[i]!=target[i]){
            str[i]++;
            ans.push_back(str);
        }
        generate(target,ans,str,i+1);
    }
public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        string str;
        generate(target,ans,str,0);
        return ans;
    }
};