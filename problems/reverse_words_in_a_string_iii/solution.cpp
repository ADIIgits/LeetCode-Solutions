class Solution {
public:
    string reverseWords(string s) {
        //build, pause at space, reverse, move on.
        int n = s.length(); string word;
        string ans = "";
        for(int i=0;i<n;i++){
            if(s[i]==' ' && word!=""){
                reverse(word.begin(),word.end());
                ans+=word + " ";
                word="";
            }
            else word+=s[i];
        }
        if(word!=""){reverse(word.begin(),word.end()); ans+=word;}
        return ans;
    }
};