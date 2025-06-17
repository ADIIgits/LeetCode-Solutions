class Solution {
    public int singleNumber(int[] nums) {
        int n=nums.length; int el=0;
        for(int i=0;i<n;i++){
            el^=nums[i];
        }
        return el;
    }
}