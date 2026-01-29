class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double avg = 0; double sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        avg = sum/double(k);
        
        double maxavg = max(avg,maxavg);
        for(int i=k;i<n;i++){
            sum-=nums[i-k];
            sum+=nums[i];
            avg = sum/double(k);
            maxavg = max(avg,maxavg); 
        }
        return maxavg;
    }
};