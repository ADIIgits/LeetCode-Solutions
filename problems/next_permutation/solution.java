class Solution {
    public static void swap(int[] arr,int a,int b){
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }
    public static void reverse(int[] nums, int a,int n){
        int p = a; int q = n-1;
        while(p<=q){
            swap(nums,p,q);
            p++;q--;
        }
    }
    public void nextPermutation(int[] nums) {
        int n = nums.length;
        int piv = -1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                piv = i;
                break;
            }
        }
        System.out.print(piv+" ");
        if(piv==-1){
            reverse(nums,0,n);
            return;
        }
        for(int i = n-1;i>piv;i--){
            if(nums[i]>nums[piv]){
                swap(nums,i,piv);
                break;
            }
        }
        reverse(nums,piv+1,n);

    }
}