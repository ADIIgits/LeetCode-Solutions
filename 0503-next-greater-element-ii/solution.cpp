class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& numsorg) {
        stack<int> st;
        int n = numsorg.size();
        vector<int> nums(numsorg);
        vector<int> nextgreater(n);
        for(int i=0;i<n;i++){
            nums.push_back(numsorg[i]);
        }
        int m = nums.size();
        for(int i=m-1;i>=0;i--){
            while(!st.empty() && nums[i%n] >= nums[st.top()]){
                st.pop();
            }
            nextgreater[i%n] = st.empty() ? -1 : nums[st.top()];
            st.push(i%n);
        }
        return nextgreater;
    }
};
