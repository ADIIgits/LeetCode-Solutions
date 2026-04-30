class Solution {
public:
    long long sumsmallest(vector<int>& arr){
        stack<int> st;
        int n = arr.size();
        long long sum = 0;
        for(int i=0;i<=n;i++){
            while(!st.empty() && ( i==n || arr[i] <= arr[st.top()])){
                int nextsmaller = i;
                int curr = st.top();
                st.pop();
                int prevsmaller = st.empty() ? -1 : st.top();

                int left = curr - prevsmaller; int right = nextsmaller - curr;
                sum  = sum + 1LL*left*right*arr[curr];
            }
            st.push(i);
        }
        return sum;
    }
    long long sumlargest(vector<int>& arr){
        stack<int> st;
        int n = arr.size();
        long long sum = 0;
        for(int i=0;i<=n;i++){
            while(!st.empty() && ( i==n || arr[i] >= arr[st.top()])){
                int nextlarger = i;
                int curr = st.top();
                st.pop();
                int prevlarger = st.empty() ? -1 : st.top();

                int left = curr - prevlarger; int right = nextlarger - curr;
                sum  = sum + 1LL*left*right*arr[curr];
            }
            st.push(i);
        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        
        return sumlargest(nums) - sumsmallest(nums);
    }
};
