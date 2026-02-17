class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        //prev.last> curr.first && prev.first<curr.first
        vector<vector<int>> ans;
        ans.push_back(nums[0]);
        for(int i=0;i<n;i++){
            if(nums[i][0] <= ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1],nums[i][1]);
            }
            else ans.push_back(nums[i]);
        }
        
        return ans;
    }
};