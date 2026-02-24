class Solution {
    void sub(vector<int>& nums,vector<vector<int>> &ans,vector<int> &vec,int i){
        int n = nums.size();
        if(i==n){
            ans.push_back(vec);
            return;
        }
        vec.push_back(nums[i]);
        sub(nums,ans,vec,i+1);
        vec.pop_back();
        int idx = i;
        while(idx<n && nums[i]==nums[idx]) idx++;
        sub(nums,ans,vec,idx);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> vec;
        sub(nums,ans,vec,0);
        return ans;
    }
};