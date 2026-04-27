class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<int> ans;
        vector<vector<int>> adjlist(V);
        vector<int> indegree(V,0);
        for(vector<int> reqcourses:prerequisites){
            int u = reqcourses[0];
            int v = reqcourses[1];
            adjlist[u].push_back(v);
            indegree[v]++;
        }
        queue<int> que;
        for(int i=0;i<V;i++){
            if(indegree[i]==0) que.push(i);
        }
        while(!que.empty()){
            int course = que.front();
            que.pop();
            for(int required_courses:adjlist[course]){
                indegree[required_courses]--;
                if(indegree[required_courses]==0) que.push(required_courses);
            }
            ans.push_back(course);
        }
        if(ans.size()!=V) return {};
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
