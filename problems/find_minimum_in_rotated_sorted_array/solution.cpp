class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int st = 0; int ed = n-1;
        if(n==2) return min(nums[0],nums[1]);
        while(st<=ed){
            int mid = st+(ed-st)/2;
            int prev=INT_MAX; int next=INT_MAX;
            if(mid!=0) prev=nums[mid-1];
            if(mid!=n-1) next=nums[mid+1];
            if(nums[mid]<prev && nums[mid]<next) return nums[mid];
            else{
                if(nums[mid]<nums[ed]){
                    ed=mid-1;
                }
                else {
                    st=mid+1;
                }
            }
            
        }
        return -1;
    }
};