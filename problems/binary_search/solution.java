class Solution {
    public static int bsearch(int[] arr,int t,int s,int e){
        if(s<=e){
            int mid = s + (e-s)/2; //or (s+e)/2;
            if(arr[mid]==t) return mid;
            else if(arr[mid]<t) return bsearch(arr,t,mid+1,e);
            else return bsearch(arr,t,s,mid-1);
        }
        return -1;
        
    }
    public int search(int[] nums, int target) {
        return bsearch(nums,target,0,nums.length-1);
    }
}