class Solution {
public:
    int searchfirst(vector<int>& nums, int target){
        int n = nums.size();
        int st = 0; int ed=n-1;
        int first=-1;
        while(st<=ed){
            int mid = st + (ed-st)/2;
            if(nums[mid]==target){
                first=mid;
                ed=mid-1;
            }
            else if(nums[mid]<target) st=mid+1;
            else ed=mid-1;
        }
        return first;
    }
    int searchsecond(vector<int>& nums, int target){
        int n = nums.size();
        int st = 0; int ed=n-1;
        int second=-1;
        while(st<=ed){
            int mid = st + (ed-st)/2;
            if(nums[mid]==target){
                second=mid;
                st=mid+1;
            }
            else if(nums[mid]<target) st=mid+1;
            else ed=mid-1;
        }
        return second;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int a = searchfirst(nums,target);
        int b = searchsecond(nums,target);
        return {a,b};
    }
};