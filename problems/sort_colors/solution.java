class Solution {
    public static void swap(int[] nums,int r, int g){
        int temp = nums[r];
        nums[r] = nums[g];
        nums[g] = temp;
    }
    public void sortColors(int[] nums) {
        int n=nums.length;
        int p=0; int q=n-1; int r=0;
        while(r<=q){
            if(nums[r]==0){
                swap(nums,r,p);
                p++; r++;
            }
            else if(nums[r]==2){
                swap(nums,r,q);
                q--;
            }
            else r++;
        }
    }
}