class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9 + 7;
        int n = arr.size();
        stack<int> st;
        vector<int> nextsmaller(n,-1);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(!st.empty() && arr[st.top()]<arr[i]){
                nextsmaller[i] = st.top();
            }
            st.push(i);
        }
        long long sum = 0;
        while(!st.empty()) st.pop();
        for(int i=0;i<n;i++){
            int nextsmall = nextsmaller[i]==-1? n : nextsmaller[i];
            int curr = 0;
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            int prevsmall = st.empty()? -1: st.top();
            long long left = i-prevsmall; long long right = nextsmall-i;
            sum  = sum + ((left*right%mod)*arr[i]%mod)%mod;
            st.push(i);
        }
        return sum%mod;
        return -1;
    }
};