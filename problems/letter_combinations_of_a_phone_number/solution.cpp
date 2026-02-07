class Solution {
    void getcombo(string &digits,unordered_map<char, string> &keypad,vector<string> &ans,string s,int i){
        int n = digits.length();
        if(s.length()==n){
            ans.push_back(s);
            return;
        }
        if(i==n) return;
        char dig = digits[i];
        string str = keypad[dig];

        for(char letter:str){
            s.push_back(letter);
            getcombo(digits,keypad,ans,s,i+1);
            s.pop_back();
        }

    }

public:
    vector<string> letterCombinations(string digits) {
        // digitlength -> string length; 
        vector<string> ans;
        unordered_map<char, string> keypad = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
        };
        getcombo(digits,keypad,ans,"",0);
        return ans;
    }
};