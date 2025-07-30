class Solution {
    public static void swap(int[] arr,int p,int q){
        int temp = arr[p];
        arr[p]=arr[q];
        arr[q]=temp;
    }
    public void sortColors(int[] nums) {
        int n = nums.length; int p=0; int q=n-1; int r=0;
        while(r<=q){
            if(nums[r]==0){
                swap(nums,r,p);
                p++;
            } else if(nums[r]==2){
                swap(nums,r,q);
                q--;
                r--;
            }
            r++;
        }
        
    }
}