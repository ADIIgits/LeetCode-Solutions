class Solution {
public:
    void dfs(unordered_map<string,priority_queue<string,vector<string>,greater<string>>> &adjlist,vector<string> &ans,string source){
        while(!adjlist[source].empty()){
            string next = adjlist[source].top();
            adjlist[source].pop();
            dfs(adjlist,ans,next);
        }
        ans.push_back(source);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,priority_queue<string,vector<string>,greater<string>>> adjlist;
        vector<string> ans;
        for(auto ticket:tickets){
            string from = ticket[0];
            string to = ticket[1];
            adjlist[from].push(to);
        }
        dfs(adjlist,ans,"JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
