class Solution {
    public int maxArea(int[] height) {
        int n = height.length;
        int p = 0; int q=n-1;
        int max = Integer.MIN_VALUE;
        while(p<q)
        {

            int curr = Math.min(height[p],height[q])*(q-p);
            
            if(curr>max)
            max=curr;

            if(height[p]<height[q])
            p++;
            else if(height[p]>height[q])
            q--;
            else{
            p++;q--;}




            
        }
        return max;
    }
}