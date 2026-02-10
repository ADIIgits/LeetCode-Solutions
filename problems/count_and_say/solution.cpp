class Solution {
    string rle(string s){
        char prev = s[0]; int count=0;
        string st = "";
        for(char c:s){
            if(prev==c) count++;
            else{
                st+=to_string(count)+prev;
                count=1;
            }
            
            prev=c;
        }
        st += to_string(count) + prev;
        cout<<st<<" ";
        return st;
    }
    
public:
    string countAndSay(int n) {
        string prev = "1";
        for(int i=1;i<n;i++){
            prev = rle(prev);
        }
        return prev;
    }
};