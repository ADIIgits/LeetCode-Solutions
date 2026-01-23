class Solution {
public:
    int vowelConsonantScore(string s) {
        unordered_set<char> vowels = {'a','e','i','o','u'};
        int c = 0; int v=0;
        for(char ch:s){
            if(!((ch>=96 && ch<=122) || (ch>=65 && ch<=92))) continue;
            if(vowels.find(ch)!=vowels.end()) v++;
            else c++;
        }
        if(c<=0) return 0;
        return floor(v/c);
    }
};