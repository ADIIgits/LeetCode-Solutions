class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //this can be solved by Kahn's algo (Topological sort) applied in reverse
        int V = graph.size();
        vector<int> ans;
        vector<vector<int>> adjlist(V);
        vector<int> outdegree(V,0);
        for(int i=0;i<V;i++){
            int currnode = i;
            for(int destnode:graph[currnode]){
                adjlist[destnode].push_back(currnode);
                outdegree[currnode]++;
            } 
        }
        queue<int> que;
        for(int i=0;i<V;i++){
            if(outdegree[i]==0) que.push(i);
        }
        while(!que.empty()){
            int currnode = que.front();
            que.pop();
            for(int source:adjlist[currnode]){
                outdegree[source]--;
                if(outdegree[source]==0) que.push(source);
            }
            ans.push_back(currnode);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
