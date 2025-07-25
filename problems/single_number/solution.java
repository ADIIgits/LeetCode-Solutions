class Solution {
    public int singleNumber(int[] nums) {
        int sumor = 0;
        for(int el:nums){
            sumor^=el;
        }
        return sumor;
    }
}