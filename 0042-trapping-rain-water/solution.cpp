class Solution {
public:
    int trap(vector<int>& height) {
        //nextpeak - lastpeak
        //maybe we keep track of prevsmaller and nextsmall.
        int n = height.size();
        vector<int> rightmax(n); vector<int> leftmax(n);
        int maxi = -1;
        for(int i=n-1;i>=0;i--){
            maxi = max(maxi,height[i]);
            rightmax[i] = maxi;
        }
        maxi = -1;
        int water=0;
        for(int i=0;i<n;i++){
            maxi = max(maxi,height[i]);
            water += min(maxi,rightmax[i]) - height[i];
        }
        return water;

    }
};
