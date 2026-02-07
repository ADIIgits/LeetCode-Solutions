class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(); int m = nums2.size();
        //my code finds midx by binarysearching on nums1. thus nums1 should be smaller. so we pass the smaller one.
        if(n>m) return findMedianSortedArrays(nums2,nums1);

        int st=0; int ed=n; int i=0; int j=0; int leftsize = (n+m+1)/2;
        int midx = -1; 

        int left1 = INT_MIN; int left2 = INT_MIN;
        int right1 = INT_MAX; int right2 = INT_MAX;
        while(st<=ed){
            int mid = st + (ed-st)/2;

            i = mid; j = leftsize - i;

            left1 = INT_MIN;
            if(i!=0) left1 = nums1[i-1];
            right1 = INT_MAX;
            if(i!=n) right1 = nums1[i];

            left2 = INT_MIN;
            if(j!=0) left2 = nums2[j-1];
            right2 = INT_MAX;
            if(j!=m) right2 = nums2[j];

            if(left1<=right2 && left2<=right1) {
                midx = mid;
                break;
            }
            else if(left1>right2) ed=mid-1;
            else st=mid+1;
        }
        if((n+m)%2==0) return ( max(left1,left2) + min(right1,right2) )/2.0;
        else return max(left1,left2);
        return 0.0;
    }
};