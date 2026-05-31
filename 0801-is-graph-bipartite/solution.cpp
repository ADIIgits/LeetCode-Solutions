class Solution {
public:
    bool can_color(vector<vector<int>>& graph,vector<int> &colored,int src){
        queue<pair<int,int>> que;
        que.push({src,0});
        colored[src] = 0;
        while(!que.empty()){
            auto [currnode,currcolor] = que.front();
            que.pop();
            for(int node:graph[currnode]){
                if(currcolor == colored[node]) return false;

                if(colored[node]==-1){
                    colored[node] = 1-currcolor;
                    que.push({node,1-currcolor});
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                if(!can_color(graph,vis,i)) return false;
            }
        }
        return true;
    }
};
