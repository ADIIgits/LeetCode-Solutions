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
        generate(nums,ans,vec,i+1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> vec;
        generate(nums,ans,vec,0);
        return ans;
    }
};
