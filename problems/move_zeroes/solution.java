class Solution {
    public static int[] swap(int p,int q,int[] nums)
    {
        int temp = nums[p];
        nums[p] = nums[q];
        nums[q]=temp;
        return nums;
    }
    
    public void moveZeroes(int[] nums) {
        int n = nums.length;
        int p=0; int q=1;
        while(q<n)
        {
            if(nums[p]==0 && nums[q]!=0){
            nums = swap(p,q,nums);
                p++;q++;
            }
            else if(nums[p]==0 && nums[q]==0)
            q++;
            else if(nums[p]!=0){
            p++; q++;}
            
        }
    }
}