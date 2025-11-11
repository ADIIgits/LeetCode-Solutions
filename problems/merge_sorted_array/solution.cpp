class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = nums1.size()-1;
        int p=m-1; int q=n-1;
        while(p>=0 && q>=0){
            if(nums1[p]>=nums2[q])
            nums1[k--] = nums1[p--];
            else
            nums1[k--] = nums2[q--];

        }
        while(p>=0){
            nums1[k--] = nums1[p--];
        }
        while(q>=0){
            nums1[k--] = nums2[q--];
        }
        
    }
};