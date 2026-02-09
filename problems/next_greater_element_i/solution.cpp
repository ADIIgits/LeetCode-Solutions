class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        stack<int> st;
        vector<int> ans;
        unordered_map<int,int> nextgreater;
        for(int i=m-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(!st.empty() && st.top()>nums2[i]) nextgreater[nums2[i]]=st.top();
            else  nextgreater[nums2[i]]=-1;

            st.push(nums2[i]);
        }

        for(int el:nums1){
            ans.push_back(nextgreater[el]);
        }
        return ans;
    }
};