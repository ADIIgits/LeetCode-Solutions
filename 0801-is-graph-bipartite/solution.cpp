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
        return parent[v]=find(parent[v]);
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
    bool isBipartite(vector<vector<int>>& graph) {
        //if two nodes belong to sae color and have edge between em, not bipartite.
        int V = graph.size();
        DSU dsu(V);
        for(int i=0;i<V;i++){
            int currnode = i;
            for(int neighbour:graph[currnode]){
                if(dsu.find(currnode)==dsu.find(neighbour)) return false;
                dsu.unite(graph[currnode][0],neighbour);
            }
            
        }
        return true;
    }
};
