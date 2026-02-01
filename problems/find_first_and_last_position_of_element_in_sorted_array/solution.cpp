class Solution {
    int bs(vector<int>& nums, int target,int dir){
        int n = nums.size();
        int st = 0; int ed = n-1;
        int res = -1;
        while(st<=ed){
            int mid = st+(ed-st)/2;
            if(nums[mid]==target){
                res = mid;
                if(dir==0) ed=mid-1;
                else st=mid+1;
            } else if(nums[mid]<target) st=mid+1;
            else ed=mid-1;
        }
        return res;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = bs(nums,target,0);
        int second = bs(nums,target,1);
        return {first,second};
    }
};