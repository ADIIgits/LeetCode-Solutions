class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //if st.top>curr, package and append to ans.
        //if st.top < curr
        vector<int> ans;
        unordered_map<int,int> map;
        stack<int> st; int n = temperatures.size();
        for(int i=n-1;i>=0;i--){
            int currtemp = temperatures[i];
            while(!st.empty() && currtemp >= st.top()){
                st.pop();
            }
            if(!st.empty() && currtemp < st.top()) ans.push_back(map[st.top()] - i);
            else ans.push_back(0);
            
            map[currtemp] = i;
            st.push(currtemp);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};