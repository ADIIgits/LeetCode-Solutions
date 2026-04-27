class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<int,int> map;
        int p=0; int q=0;
        int maxlen = 0;
        while(q<n){
            map[s[q]]++;
            while(map[s[q]]>1){
                map[s[p]]--;
                if(map[s[p]]<=0) map.erase(s[p]);
                p++;
            }
            maxlen = max(maxlen,q-p+1);
            q++;
        }
        return maxlen;
    }
};
