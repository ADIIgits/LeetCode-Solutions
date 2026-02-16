class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
       
        for(int curr:nums){
            bool isalive = true;
            while(!st.empty() && st.top()>0 && curr<0 && isalive){
                if(abs(st.top())<abs(curr)) st.pop();
                else if(abs(st.top())==-curr){
                    st.pop();
                    isalive=false;
                } else { //top is bigger than curr
                    isalive=false;
                }
            }
            if(isalive) st.push(curr);
        }
        vector<int> vec(st.size());
        for(int i=st.size()-1;i>=0;i--){
            vec[i] = st.top();
            st.pop();
        }
        return vec;

    }
};