class Solution {
public:
    string removeKdigits(string num, int k) {
        string s="";
        for(char c:num){
            // hunting for smalest c untill k chances exhaust.
            while(!s.empty() && s.back()>c && k>0){
                s.pop_back();
                k--;
            }
            s.push_back(c);
        }
        //imagine a string (or a part of string) where all digits are in ascending order. no pop will be triggered. thus k wont ever be 0. so we simply remove rest of the k digits from the back (cuz thats where largest digits are).
        while(k>0){
            s.pop_back(); k--;
        }
        int j=0;
        while(j<s.length() && s[j]=='0') j++;
        s=s.substr(j);
        if(s=="") return "0";
        else return s;

        
    }
};