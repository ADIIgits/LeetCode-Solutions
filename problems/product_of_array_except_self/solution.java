class Solution {
    public int[] productExceptSelf(int[] nums) {
        int p = 1; int q=1; int n = nums.length;
        int[] newarr = new int[n];
        for(int i=0;i<n;i++){
             newarr[n-i-1] = q;
             q*=nums[n-i-1];
        }
        
        for(int i=0;i<n;i++){
            newarr[i]*=p;
            p*=nums[i];
        }
        return newarr;

    }
}