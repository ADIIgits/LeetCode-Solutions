class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int st=0; int ed=n-1; int maxarea = INT_MIN;
        while(st<ed){
            int area = min(height[st],height[ed])*(ed-st);
            maxarea = max(maxarea,area);
            if(height[st]<height[ed]) st++;
            else ed--;
        }
        return maxarea;
    }
};