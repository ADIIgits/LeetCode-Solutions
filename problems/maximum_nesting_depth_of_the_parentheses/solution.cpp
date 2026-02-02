class Solution {
public:
    int maxDepth(string s) {
        int maxdepth = 0;
        int open=0;
        for(char c:s){
            if(c=='(') open++;
            else if(c==')') open--;
            maxdepth = max(maxdepth,open);
        }
        return maxdepth;
    }
};