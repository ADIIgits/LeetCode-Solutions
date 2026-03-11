class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //distane from origin = sqrt(xsquare + ysquare)
        priority_queue<pair<double,vector<int>>, vector<pair<double,vector<int>>>,less<pair<double,vector<int>>>> pq;
        for(vector<int> coords:points){
            double dist = sqrt(coords[0]*coords[0] + coords[1]*coords[1]);
            pq.push({dist,coords});
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;

    }
};