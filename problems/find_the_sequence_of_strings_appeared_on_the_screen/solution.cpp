class Solution {
    void type(vector<string> &ans,string s,string target,int i){
        if(s==target) return;
        s.push_back('a');
        ans.push_back(s);
        while(s[i]!=target[i]){
            s[i]++;
            ans.push_back(s);
        }
        type(ans,s,target,i+1);

    }

public:
    vector<string> stringSequence(string target) {
        vector<string> ans;
        type(ans,"",target,0);
        return ans;
    }
};