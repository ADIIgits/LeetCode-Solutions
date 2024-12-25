class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int sm=INT_MAX/2;
        for(int i=0;i<n;i++)
        {
            int j=i+1; int k=n-1; 
            while(j<k)
            {
                int sum=nums[i]+nums[j]+nums[k];
                if(abs(sum-target) < abs(sm-target))
                {
                    sm=sum;
                }
                if(sum<target)
                {
                    j++;
                }
                else if(sum>target)
                {
                    k--;
                }
                else
                {
                    return sum;
                }
            } 
        }
        
        return sm;
    }
};