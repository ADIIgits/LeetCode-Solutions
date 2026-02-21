class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        int count = 0;
        unordered_map<int,int> map = {{'a',0},{'b',0},{'c',0}};
        
        int p=0; int q=0;
        while(q<n){
            map[s[q]]++;
            //once we hit a point where a,b,c all have occurence of atleast 1, anything after that is valid. so n-q subarrays are valid.
            while(map['a']>0 && map['b']>0 && map['c']>0){
                count  += n-q; //why n-q and not q-p? cuz n-q are valid subarrays, anything after atleast one a,b,c is valid.
                map[s[p]]--;
                p++;
            }
            q++;
        }
        return count;
    }
};