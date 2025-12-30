class Solution {
    void perm(vector<int>& nums,vector<vector<int>> &allperms,vector<int> &vec,vector<bool> &visited){
        int n = nums.size();
        if(vec.size()==n){
            allperms.push_back(vec);
            return;
        }
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            visited[i]=true;
            vec.push_back(nums[i]);
            perm(nums,allperms,vec,visited);
            vec.pop_back();
            visited[i]=false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> allperms;
        vector<int> vec;
        vector<bool> visited(n,false);
        perm(nums,allperms,vec,visited);
        return allperms;
    }
};