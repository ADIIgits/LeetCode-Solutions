class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //find prevsmaller and nextsmaller then take index difference multiply by bar height 
        //there, you have the area, just maintain a max variable to track the largest one
        int n = heights.size();
        stack<int> st;
        int maxarea = 0;
        for(int i=0;i<=n;i++){
            // int currheight = heights[i];
            while(!st.empty() && (i==n || heights[i] < heights[st.top()])){
                int nextsmaller = i;
                int curr = st.top();
                st.pop();
                int prevsmaller = st.empty() ? -1 : st.top();

                int area = (nextsmaller - prevsmaller - 1) * heights[curr];
                maxarea = max(maxarea,area);
            }
            st.push(i);
        }
        return maxarea;
    }
};
