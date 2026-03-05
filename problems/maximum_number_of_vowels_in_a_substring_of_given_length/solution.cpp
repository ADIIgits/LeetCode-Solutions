class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length();
        int maxvow = 0;
        //1st ksized window
        int vow=0;
        string vowels = "aeiou";  
        for(int i=0;i<k;i++){
            if(find(vowels.begin(),vowels.end(),s[i])!=vowels.end()) vow++;
            maxvow = max(maxvow,vow);
        }
        for(int i=k;i<n;i++){
            if(find(vowels.begin(),vowels.end(),s[i])!=vowels.end()) vow++;
            if(find(vowels.begin(),vowels.end(),s[i-k])!=vowels.end()) vow--;
            maxvow = max(maxvow,vow);
        }
        return maxvow;
    }
};