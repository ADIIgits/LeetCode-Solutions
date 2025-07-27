class Solution {
    public int majorityElement(int[] nums) {
        if(nums.length==1) return nums[0];
        Arrays.sort(nums);
        int n = nums.length;
        int c=0; int candidate = 0;
        for(int i=0;i<n;i++){
            if(c==0){
                candidate = nums[i];
            }

            if(candidate==nums[i]){
                c++;
            } else {
                c--;
            }
        }
        return candidate;
    }
}