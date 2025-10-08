class Solution {
    public int majorityElement(int[] nums) {
        int n = nums.length;
        int count = 0;
        int candidate = nums[0];
        for(int i=0;i<n;i++){
            if(count<=0) candidate = nums[i];
            if(nums[i]==candidate) count++;
            else count--;

            if(count>n/2) return candidate;
            
        }
        return candidate;
    }
}