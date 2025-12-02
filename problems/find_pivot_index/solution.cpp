class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size(); 
        int sum=0; int sum2=0;
        for(int el:nums){
            sum+=el;
        }
        int left=0;
        for(int i=0;i<n;i++){
            if(left*2+nums[i]==sum) return i;
            left+=nums[i];
        }
        return -1;
    }
};