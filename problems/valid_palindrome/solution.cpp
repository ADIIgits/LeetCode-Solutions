class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        // if(n==2) return s[0]==s[1];
        int p=0; int q=n-1;
        while(p<q){
            if(isalnum(s[p])){
                if(isalnum(s[q])){
                    if(toupper(s[p])!=toupper(s[q])) return false;
                    else {p++;q--;}
                } else q--;  
            } else p++;

        }
        return true;
    }
};