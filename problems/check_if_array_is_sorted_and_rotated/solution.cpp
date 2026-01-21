class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int count=0;
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]) count++;
        }
        if(count==0 || (count==1 && nums[0]>=nums[n-1])) return true;
        else return false;
    }
};