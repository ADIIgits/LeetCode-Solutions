class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int st=0; int ed = n-1;
        while(st<ed){
            int mid = st+(ed-st)/2;
            if(nums[mid]<=nums[ed]) ed=mid;
            else st=mid+1;
        }
        return nums[st];
    }
};