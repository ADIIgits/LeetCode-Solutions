class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0; int bottom = m-1;
        int left = 0; int right = n-1;
        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++){
                ans.push_back(matrix[top][i]);
            }
            for(int i=top+1;i<=bottom;i++){
                ans.push_back(matrix[i][right]);
            }
            for(int i=right-1;i>=left;i--){
                if(top==bottom) break;
                ans.push_back(matrix[bottom][i]);
            }
            for(int i=bottom-1;i>=top+1;i--){
                if(right==left) break;
                ans.push_back(matrix[i][left]);
            }
            top++; left++; right--; bottom--;
        }
        return ans;

    }
};