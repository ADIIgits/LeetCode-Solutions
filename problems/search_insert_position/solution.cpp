class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size(); 
        int ans = -1;
        int st=0; int ed=n-1;
        while(st<=ed){
            int mid = st + (ed-st)/2;
            ans=mid;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) st=mid+1;
            else ed=mid-1;
        }
        if(target>nums[ans]) return ans+1;
        return ans;
    }
};