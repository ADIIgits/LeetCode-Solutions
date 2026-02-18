class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        unordered_map<int,int> nextgreater;
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            nextgreater[nums2[i]]=-1;
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(!st.empty()) nextgreater[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        vector<int> ans;
        for(int el:nums1){
            ans.push_back(nextgreater[el]);
        }
        return ans;
    }
};