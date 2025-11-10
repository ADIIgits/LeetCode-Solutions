class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>> triangle;
        triangle.push_back(vector<int> {1});
        if(n>1)
        triangle.push_back(vector<int> {1,1});
        
        for(int i=2;i<n;i++){
            vector<int> row;
            row.push_back(1);
            for(int j=1;j<i;j++){
                row.push_back(triangle[i-1][j-1]+triangle[i-1][j]);
            }
            row.push_back(1);

            triangle.push_back(row);
        }
        return triangle;
    }
};