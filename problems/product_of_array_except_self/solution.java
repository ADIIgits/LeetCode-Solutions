class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] prefix = new int[n];
        int[] suffix = new int[n];
        int mul=1;
        for(int i=0;i<n;i++){
            prefix[i]=mul;
            mul*=nums[i];
            
        }
        mul=1;
        for(int i=0;i<n;i++){
            suffix[n-i-1]=mul;
            mul*=nums[n-i-1];
        }
        int[] ans = new int[n];
        for(int i=0;i<n;i++){
            ans[i]=prefix[i]*suffix[i];
        }
        return ans;
    }
}