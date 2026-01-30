class Solution {
public:
    int countSegments(string s) {
        int n = s.length();
        string special = "!@#$%^&*()_+-=',.:";
        vector<string> ans;
        string word = "";
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                if(word!="") ans.push_back(word);
                word="";
            } else word+=s[i];
        }
        if(word!="") ans.push_back(word);
        return ans.size();
    }
};