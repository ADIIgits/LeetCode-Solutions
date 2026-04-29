class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int p=0; int q=0;
        int count = 0;
        unordered_map<char,int> map;
        while(q<n){
            map[s[q]]++;
            while(map['a'] > 0 && map['b'] > 0 && map['c'] > 0){
                count+=n-q;
                map[s[p]]--;
                p++;
            }
            q++;
        }
        return count;
    }
};
