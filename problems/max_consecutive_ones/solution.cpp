class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxsum = INT_MIN;
        int maxi=0;
        for(int el:nums){
            if(el==0) maxi = 0;
            else maxi++;
            maxsum = max(maxsum,maxi);
        }
        return maxsum;
    }
};