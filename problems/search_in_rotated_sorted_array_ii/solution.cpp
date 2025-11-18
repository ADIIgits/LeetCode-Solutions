class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if(n==1) return nums[0]==target;
        int st=0; int ed=n-1;
        while(st<=ed){
            int mid = st + (ed-st)/2;
            if(nums[mid]==target) return true;
            while(st<ed && nums[mid]==nums[st] && nums[mid]==nums[ed]){st++;ed--;};
            if(nums[st]<=nums[mid]){
                if(nums[st]<=target && target<nums[mid]) ed = mid-1;
                else st = mid+1;
            } else {
                if(nums[mid]<target && target<=nums[ed]) st = mid+1;
                else ed = mid-1;
            }
        }
        return false;
    }
};