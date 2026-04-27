class Solution {
public:
    int countsub(vector<int>& nums, int goal){
        int n = nums.size();
        long sum = 0;
        int p=0; int q=0;
        int count=0;
        while(q<n){
            sum+=nums[q];
            while(p<q && sum > goal){
                sum-=nums[p];
                p++;
            }
            if(sum<=goal) count+=q-p+1;
            q++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //keep adding, if sum == goal, count++, if sum > goal, shrink.
        return countsub(nums,goal) - countsub(nums,goal-1);
    }
};
