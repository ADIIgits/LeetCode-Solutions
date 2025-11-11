class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int n2 = n*n;
        long long orgsum = (n2*(n2+1))/2;
        unordered_set<int> cache; int sum=0; 
        int repeating=-1; int missing=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(cache.find(grid[i][j])!=cache.end()) repeating = grid[i][j];
                else{cache.insert(grid[i][j]);
                    sum+=grid[i][j];
                }
            }
        }
        missing = orgsum-sum;
        return {repeating,missing};
    }
};