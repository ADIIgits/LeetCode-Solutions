class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(); int m = nums2.size();
        unordered_map<int,int> nextgreater;
        stack<int> st;
        for(int i=m-1;i>=0;i--){
            while(!st.empty() && nums2[i] > nums2[st.top()]){
                st.pop();
            }
            nextgreater[nums2[i]] = st.empty() ? -1 : nums2[st.top()];
            st.push(i);
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(nextgreater[nums1[i]]);
        }
        return ans;
        //ans.push_back(nextgreater[nums1[i]])
    }
};
