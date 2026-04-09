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
    void unite(int a, int b){
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
    int numIslands(vector<vector<char>>& grid) {
        //loop over all nodes, for every node, that is and island, we check its 4 directions, if they have another island, we merge em using dsu. then at the end we loop over all nodes and count independent connected components.(find(i)==i)
        int m = grid.size(); //no of rows;
        int n = grid[0].size(); //no of cols;
        
        int N = n*m;
        DSU dsu(N);
        auto node = [](int i, int j,int n){
            return i*n + j; //this will get us the node number
        };
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='0') continue;
                //right
                if(j<n-1 && grid[i][j+1]=='1'){
                    dsu.unite(node(i,j,n),node(i,j+1,n));
                } 
                //left
                if(j>0 && grid[i][j-1]=='1'){
                    dsu.unite(node(i,j,n),node(i,j-1,n));
                } 
                //top
                if(i>0 && grid[i-1][j]=='1'){
                    dsu.unite(node(i,j,n),node(i-1,j,n));
                } 
                //bottom
                if(i<m-1 && grid[i+1][j]=='1'){
                    dsu.unite(node(i,j,n),node(i+1,j,n));
                }

            }
        }
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='0') continue;
                if(dsu.find(node(i,j,n))==node(i,j,n)) count++;
            }
        }
        return count;

    }
};
