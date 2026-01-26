class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int s=0; int e=n-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            int prev=-1; int next=-1;
            if(mid!=0) prev=nums[mid-1];
            if(mid!=n-1) next=nums[mid+1];

            if(prev!=nums[mid] && nums[mid]!=next) return nums[mid];
            else {
                if(mid%2==0){
                    if(nums[mid]==prev) e=mid-1;
                    else s=mid+1;
                } else {
                    if(nums[mid]==prev) s=mid+1;
                    else e=mid-1;
                }
            }

        }
        return -1;
    }
};