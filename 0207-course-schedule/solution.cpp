class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //make an adjacencylist where you store prerequisites for every course in a list
        //NO : you store which courses UNLOCK which courses.
        //calculate and store how many prerequisites very course have in an array (indegree array)
        //
        int V = numCourses;
        vector<int> indegree(V,0);
        vector<vector<int>> adjlist(V);
        for(vector<int> reqcourses:prerequisites){
            int a = reqcourses[0];
            int b = reqcourses[1];
            adjlist[b].push_back(a);
            indegree[a]++;
        }
        queue<int> que;
        for(int i=0;i<V;i++){
            if(indegree[i]==0) que.push(i);
        }
        int count=0;
        while(!que.empty()){
            int currcourse = que.front();
            que.pop();
            //we are kinda simulating to clear out requirements for currcourse
            for(int required_course:adjlist[currcourse]){
                indegree[required_course]--;
                if(indegree[required_course]==0) que.push(required_course);
            }
           count++;
        }
        
        return count==numCourses;
    }
};
