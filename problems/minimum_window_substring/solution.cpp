class Solution {
    bool valid(vector<int> mapwindow,vector<int> mapt){
        for(int i=0;i<58;i++){
            if(mapwindow[i]<mapt[i]) return false;
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        int minlen = INT_MAX; int start = 0;
        //window slide krvadunga, map me freq store krvata rahunga
        //ek dusrre map me target ki freq pehle store krvalunga. at everypoint dono ko compare krta rahunga, if they match save the length. and return max among them.
        if(s.length() < t.length()) return "";
        int n = s.length();
        int p = 0; int q=0;
        vector<int> mapwindow(58,0);
        vector<int> mapt(58,0);
        for(char c:t) mapt[c-'A']++;
        while(q<n){
            // char c = s[q];
            mapwindow[s[q]-'A']++;
            while(p<n && valid(mapwindow,mapt)){
                if(q-p+1 < minlen){
                    minlen = q-p+1;
                    start = p;
                } 
                mapwindow[s[p]-'A']--;
                p++;
            }
            q++;
        }
        if(minlen==INT_MAX) return "";
        return s.substr(start,minlen);
    }
};