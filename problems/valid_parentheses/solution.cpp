class Solution {
public:
    bool isValid(string s) {
        string st="";
        for(char c:s){
            if(!st.empty()){
                if(st.back()=='(' && c==')') st.pop_back();
                else if(st.back()=='{' && c=='}') st.pop_back();
                else if(st.back()=='[' && c==']') st.pop_back();
                else st.push_back(c);
            }
            else st.push_back(c);
        }
        if(st.empty()) return true;
        else return false;

    }
};