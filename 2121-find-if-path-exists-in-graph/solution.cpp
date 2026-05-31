class DSU{
    public:
    vector<int> parent;
    vector<int> size;
    DSU(int n){
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
            size[i] = 1;
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
            if(size[a] > size[b])
                swap(a,b);
            parent[a] = parent[b];
            size[b] += size[a];
        }
    }
};
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DSU dsu(n);
        for(auto edge:edges){
            int src = edge[0];
            int dst = edge[1];
            dsu.unite(src,dst);
        }
        return dsu.find(source)==dsu.find(destination);
    }
};
