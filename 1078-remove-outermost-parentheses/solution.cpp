class Solution {
public:
    string removeOuterParentheses(string s) {

        int n = s.length();
        int open = 0; int close = 0;
        string str = "";
        vector<string> primitive;
        for(char c:s){
            if(c=='(') open++;
            else if(c==')') close++;
            str+=c;
            if(open==close){
                primitive.push_back(str);
                str="";
            }
        }
        string ans= "";
        for(string st:primitive){
            string clipped_string = st.substr(1,st.length()-2);
            ans+=clipped_string;
        }
        return ans;
    }
};
