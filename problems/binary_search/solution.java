class Solution {
    public static int recsearch(int[] nums,int target,int s,int e){
        
        if(s<=e){
            int mid = s+(e-s)/2;
            if(nums[mid]==target) return mid;
            else if(target<nums[mid]) return recsearch(nums,target,s,mid-1);
            else if(target>nums[mid]) return recsearch(nums,target,mid+1,e);
        }
        return -1;  
    }
    public int search(int[] nums, int target) {
        return recsearch(nums,target,0,nums.length-1);
    }
}