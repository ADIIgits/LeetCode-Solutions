class DSU{
    public:
    vector<int> parent;
    vector<int> size;
    DSU(int n){
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int find(int v){
        if(parent[v]==v) return v;
        return parent[v] = find(parent[v]);
    }
    void unite(int a,int b){
        a = find(a);
        b = find(b);

        if(a!=b){
            if(size[a] < size[b])
                swap(a,b);
            parent[b] = a;
            size[a] += size[b];
        }
    }
};
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int N = n*m + 1; //we gon treat, the last cell as THE BOUNDARY cell
        DSU dsu(N);
        int boundary = N-1;
        auto node = [](int i,int j,int n){
            return i*n + j;
        };
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    if(i==m-1 || j==n-1 || i==0 || j==0) dsu.unite(boundary,node(i,j,n));

                    if(i<m-1 && grid[i+1][j]==1) dsu.unite(node(i,j,n),node(i+1,j,n));
                    if(i>0 && grid[i-1][j]==1) dsu.unite(node(i,j,n),node(i-1,j,n));
                    if(j>0 && grid[i][j-1]==1) dsu.unite(node(i,j,n),node(i,j-1,n));
                    if(j<n-1 && grid[i][j+1]==1) dsu.unite(node(i,j,n),node(i,j+1,n));
                }
                
            }
        }
        int secluded_ones = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && dsu.find(boundary)!=dsu.find(node(i,j,n))) secluded_ones++;
            }
        }
        return secluded_ones;
    }
};
