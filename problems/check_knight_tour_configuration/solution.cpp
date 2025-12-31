class Solution {
    int checkValidMove(int sr,int sc,int dr,int dc){
        if(sr+2==dr && sc+1==dc) return true;
        if(sr+2==dr && sc-1==dc) return true;
        if(sr-2==dr && sc+1==dc) return true;
        if(sr-2==dr && sc-1==dc) return true;

        if(sr+1==dr && sc+2==dc) return true;
        if(sr+1==dr && sc-2==dc) return true;
        if(sr-1==dr && sc+2==dc) return true;
        if(sr-1==dr && sc-2==dc) return true;

        return false;
    }
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]!=0) return false;
        map<int,vector<int>> position;
        // for(int i=0;i<n*n;i++){
        //     int r = i%n;
        //     int c = i/n;
        //     position[i] = {r,c}; 
        // }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                position[grid[i][j]]={i,j};
            }
        }
        for(int i=0;i<n*n-1;i++){
            auto src = position[i];
            auto dst = position[i+1];
            if(!checkValidMove(src[0],src[1],dst[0],dst[1])) return false;
        }
        return true;
    }
};