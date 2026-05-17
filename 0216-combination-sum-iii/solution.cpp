class Solution {
public:
    void generate(vector<vector<int>> &ans, vector<int> &vec,int sum,int k,int n,int j){
        
        if(sum > n) return;
        if(vec.size()==k){
            if(sum==n) ans.push_back(vec);
            return;
        }
        for(int i=j;i<=9;i++){
            vec.push_back(i);
            generate(ans,vec,sum+i,k,n,i+1);
            vec.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> vec;
        generate(ans,vec,0,k,n,1);
        return ans;
    }
};
