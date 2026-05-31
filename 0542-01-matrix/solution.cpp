class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(); int n = mat[0].size();
        vector<vector<int>> dist(m,vector<int>(n,-1));
        queue<vector<int>> que;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    dist[i][j]=0;
                    que.push({i,j,0});
                } 
            }
        }
        

        while(!que.empty()){
            vector<int> currnode = que.front();
            que.pop();
            int row = currnode[0]; 
            int col = currnode[1];
            int level = currnode[2];
            //down
            int r = row+1; int c = col;
            if(r < m && mat[r][c]==1){
                dist[r][c]=level+1;
                mat[r][c]=0;
                que.push({r,c,level+1});
            }
            //up
            r = row-1; c = col;
            if(r >= 0 && mat[r][c]==1){
                mat[r][c]=0;
                dist[r][c]=level+1;
                que.push({r,c,level+1});
            }
            //left
            r = row; c = col-1;
            if(c >= 0 && mat[r][c]==1){
                mat[r][c]=0;
                dist[r][c]=level+1;
                que.push({r,c,level+1});
            }
            //right
            r = row; c = col+1;
            if(c < n && mat[r][c]==1){
                mat[r][c]=0;
                dist[r][c]=level+1;
                que.push({r,c,level+1});
            }

        }
        return dist;
    }
};
