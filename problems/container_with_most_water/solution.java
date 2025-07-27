class Solution {
    public int maxArea(int[] height) {
        int n = height.length;
        int p = 0; int q = n-1;
        int maxarea = Integer.MIN_VALUE;
        while(p<q){
            int area = (q-p)*Math.min(height[p],height[q]);
            maxarea = Math.max(maxarea,area);
            if(height[p]<height[q])
            p++;
            else if(height[p]>height[q])
            q--;
            else{
                p++;q--;
            }

        }
        return maxarea;
    }
}