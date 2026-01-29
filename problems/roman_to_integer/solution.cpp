class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        unordered_map<char,int> roman = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int prev = 0; int number=0;
        for(int i=n-1;i>=0;i--){
            char c = s[i];
            int cval = roman[c];
            if(cval>=prev){
                number+=cval;
            } else {
                number-=prev;
                number += prev-cval;
            }
            prev = cval;
        }
        return number;

    }
};