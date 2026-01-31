class Solution {
public:
    string removeDuplicates(string s) {
        vector<char> st;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(st.size()>0 && st.back()==s[i]) st.pop_back();
            else st.push_back(s[i]);
        }
        string str = "";
        for(int i=0;i<st.size();i++){
            str+=st[i];
        }
        return str;

    }
};