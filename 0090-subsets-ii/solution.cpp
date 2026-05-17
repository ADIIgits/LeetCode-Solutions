class Solution {
public:
    void generate(vector<int>& nums,vector<vector<int>> &ans,vector<int> &vec,int i){
        int n = nums.size();
        if(i==n){
            ans.push_back(vec);
            return;
        }
        vec.push_back(nums[i]);
        generate(nums,ans,vec,i+1);
        vec.pop_back();
        int j = i;
        while(j<n && nums[i]==nums[j]) j++;
        generate(nums,ans,vec,j);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> vec;
        vector<vector<int>> ans;
        generate(nums,ans,vec,0);
        return ans;
    }
};
