class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        vector<int> ans;
        for(int i=0;i<n;i++){
            int curr = asteroids[i];
            bool isalive = true;
            while(isalive && !st.empty() && st.top() > 0 && curr < 0){
                if(abs(st.top()) < abs(curr)) 
                    st.pop();
                else if(abs(st.top()) == abs(curr)){
                    st.pop();
                    isalive = false;
                }
                else if(abs(st.top()) > abs(curr)) 
                    isalive = false;
            }
            if(isalive){
                st.push(curr);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
