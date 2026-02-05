class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int p=0; int q=0;
        vector<int> freq(26,0); int maxfreq=0; int maxlen=0;
        while(q<n){
            int cq = s[q]-'A';
            freq[cq]++;
            maxfreq = max(maxfreq,freq[cq]);
            //int currlen = q-p+1; //this way, currlen is only calculated once, but p and q are constantly changing
            while(p<q && q-p+1 - maxfreq > k){
                int cp = s[p]-'A';
                freq[cp]--;
                p++;
            }
            maxlen = max(maxlen,q-p+1);
            q++;
        }
        return maxlen;
    }
};