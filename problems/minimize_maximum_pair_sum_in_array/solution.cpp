class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN; int mini = INT_MAX;
        int st=0; int ed = n-1;
        sort(nums.begin(),nums.end());
        while(st<ed){
            maxi = max(maxi,nums[st]+nums[ed]);
            st++;ed--;
        }

        // for(int el:nums){
        //     maxi = max(maxi,el);
        //     mini = min(mini,el);
        // }
        return maxi;
    }
};