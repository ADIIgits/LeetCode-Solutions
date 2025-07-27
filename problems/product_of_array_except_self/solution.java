class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] suffix = new int[n];
        int prodp = 1; int prods = 1;
        for(int i=0;i<n;i++){
            suffix[n-i-1] = prods;
            prods*=nums[n-i-1];
        }
        for(int i=0;i<n;i++){
            suffix[i] = prodp*suffix[i];
            prodp*=nums[i];
            
        }
        return suffix;
    }
}