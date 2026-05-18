class Solution {
public:
    void generate(string &digits,vector<string> &ans,unordered_map<char,string> &keypad,string s,int i){
        int n = digits.size();
        if(s.length()==n){
            ans.push_back(s);
            return;
        }
        string letters = keypad[digits[i]];
        for(char c:letters){
            s.push_back(c);
            generate(digits,ans,keypad,s,i+1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string> ans;
        unordered_map<char,string> keypad = {
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };

        generate(digits,ans,keypad,"",0);
        return ans;
    }
};
