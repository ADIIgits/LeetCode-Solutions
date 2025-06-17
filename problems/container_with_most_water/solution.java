class Solution {
    public int maxArea(int[] height) {
        int maxarea = Integer.MIN_VALUE;
        int n = height.length;
        int st = 0; int ed = n-1;
        while(st<ed){
            int currarea = Math.min(height[ed] , height[st]) * (ed-st);
            maxarea = Math.max(maxarea,currarea);
            if(height[st]<height[ed]){
                st++;
            } else if(height[ed] < height[st]){
                ed--;
            } else{
                st++; ed--;
            }
        }
        return maxarea;
    }
}