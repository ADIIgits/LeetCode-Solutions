class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //todo
        int n = nums.size();
        int p=0; int q=0;
        int minLen = INT_MAX; int sum = 0;
        while(q<n){
            if(sum<target){
                sum+=nums[q];
            }
            while(sum>=target){
                minLen = min(minLen,q-p+1); 
                sum-=nums[p++];
                
            }
            q++;
        }
        if(minLen==INT_MAX) return 0;
        return minLen;
    }
};