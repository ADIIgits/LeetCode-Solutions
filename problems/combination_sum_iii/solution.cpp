class Solution {
    void combosum(int k,int n,vector<vector<int>> &ans,vector<int> &vec,int j){
        if(vec.size()==k){
            int sum=0;
            for(int el:vec) sum+=el;
            if(sum==n) ans.push_back(vec);
            return;
        }
        if(j==10) return;
        for(int i=j;i<=9;i++){
            // if(find(vec.begin(),vec.end(),i)!=vec.end()) continue;
            vec.push_back(i);
            combosum(k,n,ans,vec,i+1);
            vec.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> vec;
        combosum(k,n,ans,vec,1);
        return ans;
    }
};