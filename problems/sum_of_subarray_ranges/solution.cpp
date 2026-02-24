class Solution {
    int mod = 1e9 + 7;
    long long sumsmallest(vector<int>& nums){
        int n = nums.size();
        long long sum = 0;
        stack<int> st;
        vector<int> nextsmaller(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            nextsmaller[i] = st.empty()? n : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            int prevsmall = st.empty()? -1 : st.top();
            int nextsmall = nextsmaller[i];
            long long subcount = (i-prevsmall)*(nextsmall-i);
            sum+=(subcount*nums[i]);
            st.push(i);
        }
        return sum;
    }
    long long sumlargest(vector<int>& nums){
        int n = nums.size();
        long long sum = 0;
        stack<int> st;
        vector<int> nextgreater(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            nextgreater[i] = st.empty()? n : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            int prevlarge = st.empty()? -1 : st.top();
            int nextlarge = nextgreater[i];
            long long subcount = (i-prevlarge)*(nextlarge-i);
            sum+=(subcount*nums[i]);
            st.push(i);
        }
        return sum;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        return sumlargest(nums) - sumsmallest(nums);
    }
};