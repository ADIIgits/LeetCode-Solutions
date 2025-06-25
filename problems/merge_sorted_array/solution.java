class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int p = m-1; int q=n-1; int l=(m+n)-1;
        while(p>=0 && q>=0){
            if(nums1[p]<nums2[q]){
                nums1[l--] = nums2[q--];
            } else {
                nums1[l--]=nums1[p--];
            }
        }
        while(l>=0 && q>=0){
            nums1[l--]=nums2[q--];
        }
           
    }
        
}