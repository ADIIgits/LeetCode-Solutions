class Solution {
    public int findPeakElement(int[] nums) {
        int n=nums.length;
        int st=0; int ed=n-1;
        
        
        while(st<=ed){
            int mid = st + (ed-st)/2;
            int midel = nums[mid];
            int prev = Integer.MIN_VALUE;
            int next = Integer.MIN_VALUE;
            if(mid!=0) prev=nums[mid-1];
            if(mid!=n-1) next=nums[mid+1];

            if(prev<midel && next<midel) return mid;

            if(midel<next) st=mid+1;
            else ed=mid-1;  
        }
        return 0;
    }
}