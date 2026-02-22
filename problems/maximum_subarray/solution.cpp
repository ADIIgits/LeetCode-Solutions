class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0; int maxsum =INT_MIN;
        for(int el:nums){
            if(sum<0) sum=0;
            sum+=el;
            maxsum = max(maxsum,sum);
            
        }
        return maxsum;

    }
};