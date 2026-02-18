class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        //area = nextsmaller index - prevsmaller index - 1 * height[i] (curr bar height)
        stack<int> st; int prevsmaller = -1;
        stack<int> stac;
        int maxarea = 0;
        for(int i=0;i<=n;i++){
            int currheight = i==n? 0 : heights[i];
            while(!st.empty() && heights[st.top()]>=currheight){
                int nextsmaller = i;
                int curr = st.top();
                st.pop();
                prevsmaller = st.empty()? -1 : st.top();
                int area = (nextsmaller - prevsmaller - 1)*heights[curr];
                maxarea = max(maxarea,area);
            }
            st.push(i);
        }
        return maxarea;
    }
};