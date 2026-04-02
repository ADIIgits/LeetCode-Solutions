class Solution {
    void bfs(vector<vector<int>>& isconnected,vector<bool> &visited,int i){
        queue<int> que;
        int n = isconnected.size();
        que.push(i);
        while(!que.empty()){
            int node = que.front();
            visited[node]=true;
            que.pop();
            for(int i=0;i<n;i++){
                if(visited[i]) continue;
                if(isconnected[node][i]) que.push(i);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;
        int n = isConnected.size();
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                bfs(isConnected,visited,i);
                count++;
            }
        }
        return count;
    }
};
