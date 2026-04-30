class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9 + 7;
        int n = arr.size();
        stack<int> st;
        long sum = 0;
        for(int i=0;i<=n;i++){
            int nextsmaller = n; int prevsmaller = -1; int curr = 0;
            while(!st.empty() && (i==n || arr[i] < arr[st.top()])){
                nextsmaller = i;
                curr = st.top();
                st.pop();
                prevsmaller = st.empty() ? -1 : st.top();
                int left = curr - prevsmaller; int right = nextsmaller - curr;
                sum = sum + (1LL * (left)%mod * (right)%mod * arr[curr] )%mod;
            }
            st.push(i);
        }
        return sum%mod;
    }
};
