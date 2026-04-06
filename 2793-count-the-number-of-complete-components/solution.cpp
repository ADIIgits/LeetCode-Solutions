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
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for(vector<int> edge:edges){
            int u = edge[0];
            int v = edge[1];
            dsu.unite(u,v);
        }
        //count nodes in each componenet
        unordered_map<int,int> nodecount;
        for(int i=0;i<n;i++) nodecount[dsu.find(i)]++;

        //counting edges in each component
        unordered_map<int,int> edgecount;
        for(vector<int> edge:edges) edgecount[dsu.find(edge[0])]++;


        int count=0;
        //nodecount has all the roots. aka all roots of connected components
        //so we simply access the connected components and how many node and edges it has
        // and verify if nodecount and edge count chcks out, cuz closed complete connected components has 
        //edges = n * (n - 1) / 2, every node is connected to n-1 (all other nodes) so n*n-1, but edge exist between 2 nodes. so (n*n-1)/2
        for(auto [root,nodes]:nodecount){
            if(edgecount[root]==nodes*(nodes-1)/2) count++;
        }
        return count;
    }
};
