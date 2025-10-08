class Solution {
    public int maxArea(int[] height) {
        int n = height.length;
        int maxwater = Integer.MIN_VALUE;
        int p=0; int q=n-1;
        while(p<q){
            int area = Math.min(height[p],height[q]) * (q-p);
            maxwater = Math.max(maxwater,area);

            if(height[p]<height[q]) p++;
            else q--;
        }
        return maxwater;
    }
}