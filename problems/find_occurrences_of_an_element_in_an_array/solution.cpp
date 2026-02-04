class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int n = nums.size();
        int m = queries.size();
        vector<int> occurs;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[i]==x) occurs.push_back(i);
        }
        for(int i=0;i<m;i++){
            if(queries[i]<=occurs.size()) ans.push_back(occurs[queries[i]-1]);
            else ans.push_back(-1);
        }
        return ans;
    }
};