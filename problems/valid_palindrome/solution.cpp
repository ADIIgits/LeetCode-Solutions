class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int st=0; int ed=n-1;
        while(st<ed){
            if(isalnum(s[st])){
                if(isalnum(s[ed])){
                    if(tolower(s[st])!=tolower(s[ed])) return false;
                    else{st++;ed--;}
                }
                else ed--;
            }
            else st++;
        }
        return true;
    }
};