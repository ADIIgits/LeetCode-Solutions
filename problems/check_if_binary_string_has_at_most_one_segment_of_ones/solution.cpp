class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.length();
        if(n==1) return s[0]=='1';
        int count=0;
        for(int i=0;i<n;){
            int j = i;
            while(s[j]=='1') j++;

            if(j>i){ i=j; count++;}
            else i++;
        }
        if(count<=1) return true;
        else return false;
    }
};