class Solution {
    public int peakIndexInMountainArray(int[] arr) {
        int n = arr.length;
        int st=1; int ed=n-2;
        while(st<=ed){
            int mid = st + (ed-st)/2;
            if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]) return mid;

            if(arr[mid]<arr[mid+1]) st=mid+1;
            else ed=mid-1;
        }
        return -1;
    }
}