class Solution {
public:
    void perm(vector<int>& nums,vector<vector<int>> &ans,vector<int> &vec,vector<bool> &vis){
        int n = nums.size();
        if(vec.size()==n){
            ans.push_back(vec);
        }
        for(int i=0;i<n;i++){
            if(vis[i]) continue;

            vis[i] = true;
            vec.push_back(nums[i]);
            perm(nums,ans,vec,vis);
            vec.pop_back();
            vis[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> vec;
        vector<bool> vis(n,false);
        perm(nums,ans,vec,vis);
        return ans;
    }
};
