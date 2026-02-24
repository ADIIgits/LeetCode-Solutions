class Solution {
    void sub(vector<int>& nums,vector<int> &vec,vector<vector<int>> &ans,int i){
        int n = nums.size();
        if(i==n){
            ans.push_back(vec);
            return;
        } 
        vec.push_back(nums[i]);
        sub(nums,vec,ans,i+1);
        vec.pop_back();
        sub(nums,vec,ans,i+1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> vec;
        sub(nums,vec,ans,0);
        return ans;
    }
};