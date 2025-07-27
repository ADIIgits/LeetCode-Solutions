class Solution {
    public int search(int[] nums, int target) {
        int n = nums.length;
        int st=0; int ed = n-1;
        while(st<=ed){
            int mid = st + (ed-st)/2;
            if(nums[mid]==target)
            return mid;

            if(nums[st]<=nums[mid]){
                if(target<=nums[mid] && target>=nums[st])
                ed=mid-1;
                else
                st=mid+1;
            } else {
                if(target<=nums[ed] && target>=nums[mid])
                st=mid+1;
                else
                ed=mid-1;

            }

            
        }
        return -1;
    }
}