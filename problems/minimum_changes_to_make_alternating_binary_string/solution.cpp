class Solution {
    int moves(string s,char start){
        int n = s.length();
        string st = "";
        int move=0;
        bool one = start == '0' ? false : true;
        for(int i=0;i<n;i++){
            if(one) st+='1';
            else st+='0';
            one = !one;
        }
        for(int i=0;i<n;i++){
            if(st[i]!=s[i]) move++;
        }
        return move;
    }
public:
    int minOperations(string s) {
        int n = s.length();
        return min(moves(s,'1'),moves(s,'0'));
    }
};