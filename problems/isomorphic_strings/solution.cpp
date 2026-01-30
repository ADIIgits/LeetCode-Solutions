class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        int n = s.length();
        int m = t.length();
        unordered_map<char,char> mapper(n);
        unordered_map<char,char> mapperval(n);
        for(int i=0;i<n;i++){
            if(mapper.find(s[i])!=mapper.end() && mapper[s[i]]!=t[i]) return false;
            if(mapperval.find(t[i])!=mapperval.end() && mapperval[t[i]]!=s[i]) return false;

            mapper[s[i]]=t[i];
            mapperval[t[i]]=s[i];
        }
        return true;
    }
};