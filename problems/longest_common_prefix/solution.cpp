class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //dont think to access all of em, and compare all of them at once., just need previous one.
        if(strs.size()==1) return strs[0];
        string prev = strs[0];
        string ans = "";
        for(string str:strs){
            int n = str.length();
            int k = 0;
            string common = "";
            while(k<n && prev[k]==str[k]){
                common+=str[k];
                k++;
            }
            int an = ans.length(); int cn = common.length();
            prev = common;
        }
        return prev;
    }
};