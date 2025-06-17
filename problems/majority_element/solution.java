class Solution {
    public int majorityElement(int[] nums) {
        int n = nums.length;
        int candidate = 0; int c = 0;
        for(int i=0;i<n;i++){
            if(c == 0){
                candidate = nums[i];
                c=0;
            } 

            if(candidate == nums[i]){
                c++;
            } else {
                c--;
            }
        }
        return candidate;
    }
}