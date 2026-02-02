class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int p=0; int q=0;
        vector<int> freq(256,0);
        int maxlen=0;
        while(q<n){
            freq[s[q]]++;
            while(freq[s[q]]>1){
                freq[s[p]]--;
                p++;
            }
            maxlen = max(maxlen,q-p+1);
            q++;
        }
        return maxlen;
    }
};