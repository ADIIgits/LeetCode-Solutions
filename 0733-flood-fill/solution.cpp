class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(); int m = image[0].size();
        int org_color = image[sr][sc];

        vector<vector<bool>> vis(n,vector<bool>(m,false));
        queue<pair<int,int>> que;
        que.push({sr,sc});
        vis[sr][sc] = true;
        while(!que.empty()){
            auto [currrow,currcol] = que.front();
            image[currrow][currcol] = color;
            que.pop();
            int crow = currrow+1; int ccol = currcol;
            if(crow < n && crow >= 0 && ccol < m && ccol >=0 && image[crow][ccol]==org_color){
                if(!vis[crow][ccol]){
                    vis[crow][ccol] = true;
                    que.push({crow,ccol});
                }
            }
            crow = currrow-1; ccol = currcol;
            if(crow < n && crow >= 0 && ccol < m && ccol >=0 && image[crow][ccol]==org_color){
                if(!vis[crow][ccol]){
                    vis[crow][ccol] = true;
                    que.push({crow,ccol});
                }
            }
            crow = currrow; ccol = currcol+1;
            if(crow < n && crow >= 0 && ccol < m && ccol >=0 && image[crow][ccol]==org_color){
                if(!vis[crow][ccol]){
                    vis[crow][ccol] = true;
                    que.push({crow,ccol});
                }
            }
            crow = currrow; ccol = currcol-1;
            if(crow < n && crow >= 0 && ccol < m && ccol >=0 && image[crow][ccol]==org_color){
                if(!vis[crow][ccol]){
                    vis[crow][ccol] = true;
                    que.push({crow,ccol});
                }
            }
        }
        return image;
    }
};
