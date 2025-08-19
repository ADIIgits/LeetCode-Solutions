class Solution {
    public int singleNumber(int[] nums) {
        int el = 0;
        for(int num:nums){
            el^=num;
        }
        return el;
    }
}