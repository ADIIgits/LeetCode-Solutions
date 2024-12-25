class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0; int e=n-1;
        int mid;
        if(target>nums[n-1])
        return n;
        
        while(s<=e)
        {
            mid=(s+e)/2;
            if(nums[mid]==target){
            return mid;}
            else if(nums[mid]<target){
            s=mid+1;}
            else{
            e=mid-1;}

            
        }
        return s;
        // if(n==2)
        // {
        //     if(nums[0]<target && nums[1]>=target)
        //     return 1;
        // }
        // for(int i=1;i<n;i++)
        // {
        //     if(nums[i-1]<target && nums[i]>=target)
        //     {
        //         return i;
        //     }
        //     else if(nums[i-1]<=target && nums[i]>target)
        //     {
        //         return i-1;
        //     }
        // }
        // if(target<nums[0])
        // return 0;
        // else if(target>nums[n-1])
        // return n;
        // else
        // return -1;
    }
};