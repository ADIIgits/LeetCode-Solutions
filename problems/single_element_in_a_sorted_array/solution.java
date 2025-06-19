class Solution {
    public int singleNonDuplicate(int[] nums) {
        int n = nums.length;
        int st=0; int ed = nums.length-1;
        while(st<=ed){
            int mid = st + (ed-st)/2;
            int prev=-1; int next = -1;
            if(mid!=0){
                prev=nums[mid-1];
            }
            if(mid!=n-1){
                next=nums[mid+1];
            }
            if(prev!=nums[mid] && nums[mid]!=next)
            return nums[mid];

            if(mid%2==0){
                if(nums[mid]==prev)
                ed=mid-1;
                else
                st=mid+1;
            } else{
                if(nums[mid]==prev)
                st=mid+1;
                else
                ed=mid-1;
            }
        }
        return -1;
    }
}