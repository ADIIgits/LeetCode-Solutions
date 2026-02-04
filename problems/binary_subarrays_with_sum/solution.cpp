class Solution {
    int countsub(vector<int>& nums, int goal){
        int n = nums.size();
        int count=0; int sum=0;
        int p=0; int q=0;
        while(q<n){
            sum+=nums[q];
           
            while(p<q && sum>goal){
                sum-=nums[p];
                p++;
            }
            int currlen = q-p+1;
            if(sum<=goal) count+=currlen;
            q++;
        }
        return count;

    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        return countsub(nums,goal)-countsub(nums,goal-1);
    }
};