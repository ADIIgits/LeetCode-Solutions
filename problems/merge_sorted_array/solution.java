class Solution {
    public static void swap(int[] arr,int a,int b){
        int temp = arr[a];
        arr[a]=arr[b];
        arr[b]=temp;
    }
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int p = m-1; int q = n-1; int l = m+n-1;
        while(p>=0 && q>=0){
            if(nums1[p]>nums2[q]){
                swap(nums1,l,p);
                l--; p--;
            } else {
                nums1[l]=nums2[q];
                l--;q--;
            }
        }
        while(q>=0){
            nums1[l]=nums2[q];
            l--; q--;
        }
    }
}