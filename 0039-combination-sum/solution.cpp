class Solution {

public:
    void calc(vector<int>& arr, vector<vector<int>> &ans, vector<int> &vec, int target,int sum,int i){
        int n = arr.size();
        if(i==n) return;
        if(sum==target){
            ans.push_back(vec);
            return;
        } else if(sum > target) return; // since its sorted, if here only sum becomes > target, 
        //no point exploring further
        vec.push_back(arr[i]); // choose da element
        calc(arr,ans,vec,target,sum+arr[i],i); //dont move on tho, 
        //keep adding this element only. explore this path

        vec.pop_back(); //pop
        //backtrack
        calc(arr,ans,vec,target,sum,i+1); // now move on to explore other elements.
        
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans; 
        vector<int> vec;
        sort(candidates.begin(),candidates.end());
        calc(candidates,ans,vec,target,0,0);
        return ans;

        
    }
};
