class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n,false);
        queue<int> que;
        que.push(0);
        visited[0]=true;
        while(!que.empty()){
            int node = que.front();
            que.pop();
            for(int key:rooms[node]){
                if(visited[key]) continue;
                que.push(key);
                visited[key]=true;
            }
        }
        for(bool status:visited){
            if(status==false) return false;
        }
        return true;
    }
};
