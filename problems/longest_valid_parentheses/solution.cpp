class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        stack<int> st; st.push(-1); int maxlen=0;
        for(int i=0;i<n;i++){
            char c = s[i];
            if(c=='(') st.push(i);
            else{
                if(c==')') st.pop();
                if(st.empty()) st.push(i);
                else maxlen = max(maxlen,i-st.top());
            }
            
        }
        return maxlen;
    }
};