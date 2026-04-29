class Solution {
public:
    bool isvalid(vector<int> &sf,vector<int> &tf){
        for(int i=0;i<58;i++){
            if(sf[i] < tf[i]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n = s.length(); int m = t.length();
        vector<int> tf(58,0);
        vector<int> sf(58,0);
        for(int i=0;i<m;i++){
            tf[t[i]-'A']++;
        }
        int p=0; int q=0;
        int start = 0;
        int minlen = INT_MAX;
        while(q<n){
            sf[s[q]-'A']++;
            while(p<n && isvalid(sf,tf)){
                if(minlen > q-p+1){
                    minlen = q-p+1;
                    start = p;
                }
                sf[s[p]-'A']--;
                p++;
            }
            q++;
        }
        return minlen==INT_MAX ? "" : s.substr(start,minlen);
    }
};
