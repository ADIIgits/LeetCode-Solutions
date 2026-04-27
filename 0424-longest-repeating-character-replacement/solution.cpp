class Solution {
public:
    int characterReplacement(string s, int k) {
        //currlen - maxfreq  = distrinct count, which should always be less than k
        int n = s.length();
        unordered_map<int,int> map;
        int maxfreq = 0;
        int maxlen = 0;
        int p = 0; int q = 0;
        while(q<n){
            map[s[q]]++;
            if(map[s[q]] > maxfreq) maxfreq = map[s[q]];
            while(q-p+1 - maxfreq > k){
                map[s[p]]--;
                p++;
            }
            maxlen = max(maxlen,q-p+1);
            q++;
        }
        return maxlen;
    }
};
