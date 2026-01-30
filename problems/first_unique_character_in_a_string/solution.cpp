class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        vector<pair<int,int>> alphafreq(256,{0,-1});
        for(int i=0;i<n;i++){
            char c = s[i];
            if(alphafreq[c].second==-1) alphafreq[c].second=i;
            alphafreq[c].first++;
        }
        int firstidx = INT_MAX;
        for(int i=0;i<256;i++){
            if(alphafreq[i].first==1){
                firstidx = min(firstidx,alphafreq[i].second);
            }
        }
        if(firstidx==INT_MAX) return -1;
        return firstidx;
    }
};