class Solution {
public:
    void generate(vector<int>& arr, vector<vector<int>> &ans,vector<int> &vec,int target,int sum,int i){
        int n = arr.size();
    
        if(sum > target) return;
        if(sum==target){
            ans.push_back(vec);
            return;
        }
        if(i==n) return;

        vec.push_back(arr[i]);
        generate(arr,ans,vec,target,sum+arr[i],i+1);
        vec.pop_back();
        int j = i;
        while(j<n && arr[i]==arr[j]) j++;
        generate(arr,ans,vec,target,sum,j);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> vec;
        generate(candidates,ans,vec,target,0,0);
        return ans;
    }
};
