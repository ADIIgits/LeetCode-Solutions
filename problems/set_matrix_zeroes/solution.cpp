class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> zero(n,vector<int>(m,1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0) zero[i][j]=-1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(zero[i][j]==-1){
                    for(int p=0;p<n;p++) matrix[p][j]=0;
                    for(int p=0;p<m;p++) matrix[i][p]=0;
                }
            }
        }
    }
};