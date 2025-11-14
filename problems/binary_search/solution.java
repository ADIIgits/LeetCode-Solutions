class Solution {
    public int search(int[] nums, int target) {
        int n = nums.length;
        int st=0; int ed=n-1;
        while(st<=ed){
            int mid = st + (ed-st);
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) st++;
            else ed--;
        }
        return -1;
    }
}