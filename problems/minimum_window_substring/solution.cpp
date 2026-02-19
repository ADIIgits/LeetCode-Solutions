class Solution {
    bool isvalid(vector<int> alphas,vector<int> alphat){
        for(int i=0;i<58;i++){
            if(alphas[i]<alphat[i]) return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<int> alphat(58,0);
        vector<int> alphas(58,0);
        for(int i=0;i<m;i++) alphat[t[i]-'A']++;
        int minsize = INT_MAX;
        int start = 0;
        int p=0; int q=0;
        while(q<n){
            alphas[s[q]-'A']++;
            while(p<n && isvalid(alphas,alphat)){
                alphas[s[p]-'A']--;
                if(minsize>q-p+1){
                    minsize = q-p+1;
                    start=p;
                }
                p++;
            }
            q++;
        }
        if(minsize==INT_MAX) return "";
        return s.substr(start,minsize);
        
    }
};