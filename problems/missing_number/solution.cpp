class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int orgsum = (n*(n+1))/2;
        int sum=0;
        for(int el:nums) sum+=el;
        return orgsum-sum;
    }
};