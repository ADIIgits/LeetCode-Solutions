class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size(); 
        vector<bool> vis(n,false);
        queue<int> que;
        que.push(0);
        vis[0]=true;
        while(!que.empty()){
            int currroom = que.front();
            que.pop();
            for(int key:rooms[currroom]){
                if(vis[key]) continue;
                vis[key]=true;
                que.push(key);
            }
        }

        for(bool status:vis){
            if(status==false) return false;
        }
        return true;
    }
};
