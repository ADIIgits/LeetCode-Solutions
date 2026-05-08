class Solution {
public:
    void generate(vector<int>& nums,int i,vector<int> vec,vector<vector<int>> &ans){
        int n = nums.size();
        if(i==n){
            ans.push_back(vec);
            return;
        }
        vec.push_back(nums[i]);
        generate(nums,i+1,vec,ans);
        vec.pop_back();
        generate(nums,i+1,vec,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> vec;
        generate(nums,0,vec,ans);
        return ans;
    }
};
