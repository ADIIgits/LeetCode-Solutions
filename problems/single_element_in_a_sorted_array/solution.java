class Solution {
    public int singleNonDuplicate(int[] nums) {
        int n = nums.length;
        if(n==1)
        return nums[0];
        
        int st = 0; int ed = n-1;
        while(st<=ed){
            int mid = st + (ed-st)/2;
            int prev = -1; int next = -1;
            if(mid!=0){
                prev=nums[mid-1];
            }
            if(mid!=n-1){
                next=nums[mid+1];
            }

            if(prev!=nums[mid] && next!=nums[mid])
                return nums[mid];

            if(mid%2==0){
                if(prev==nums[mid])
                ed=mid-1;
                else
                st=mid+1;
            } else {
                if(prev==nums[mid])
                st=mid+1;
                else
                ed=mid-1;
            }
        }
        return -1;
    }
}