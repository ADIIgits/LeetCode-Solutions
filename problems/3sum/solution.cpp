class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int st=i+1; int ed=n-1;
            while(st<ed){
                int sum = nums[i]+nums[st]+nums[ed];
                if(sum==0){
                    ans.push_back(vector<int>{nums[i],nums[st],nums[ed]});
                    st++;ed--;
                    while(st<ed && nums[st]==nums[st-1]) st++;
                    while(st<ed && nums[ed]==nums[ed+1]) ed--;
                }
                else if(sum<0) st++;
                else ed--;

            }
            
        }
        return ans;
    }
};