class Solution {
public:
    string removeKdigits(string num, int k) {
        //traverse, put it in stack, if new smaller than top found, pop untill equal or smaller. 
        //do this under k times 
        int n = num.length();
        stack<char> st;
        for(int i=0;i<n;i++){
            char curr = num[i];
            while(!st.empty() && curr < st.top() && k > 0){
                st.pop(); k--;
            }
            st.push(num[i]);
        }
        while(k > 0 && !st.empty()){
            st.pop(); k--;
        }
        string str = "";
        while(!st.empty()){
            str += st.top();
            st.pop();
        }
        reverse(str.begin(),str.end());
        int i=0;
        while(i < str.size() && str[i]=='0') i++;
        str = str.substr(i,str.size());
        return str.empty() ? "0" : str;
    }
};
