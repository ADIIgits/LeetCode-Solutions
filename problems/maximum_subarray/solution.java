class Solution {
    public int maxSubArray(int[] nums) {
        int currsum = 0; int sum = Integer.MIN_VALUE;
        int n = nums.length;
        for(int el:nums){
            if(currsum<0)
            currsum=0;
            currsum+=el;
            sum=Math.max(currsum,sum);
        }
        return sum;
    }
}