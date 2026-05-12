class Solution {
    bool ispalindrome(string str){
        int n = str.length();
        for(int i=0;i<n/2;i++){
            if(str[i]!=str[n-i-1]) return false;
        }
        return true;
    }
    void parts(string s,vector<vector<string>> &ans,vector<string> &vec,int i){
        int n = s.length();
        if(i==n){
            ans.push_back(vec);
            return;
        }
        for(int j=i;j<n;j++){
            string str = s.substr(i,j-i+1);
            if(ispalindrome(str)){
                vec.push_back(str);
                parts(s,ans,vec,j+1);
                vec.pop_back();
            }
            
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        //pas str+s[i]
        vector<string> vec;
        parts(s,ans,vec,0);
        return ans;
    }
};
