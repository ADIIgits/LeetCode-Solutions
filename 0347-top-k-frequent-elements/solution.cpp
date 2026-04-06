class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int> map;
        auto comp = [](const pair<int,int> &a,const pair<int,int> &b){
            return a.second > b.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(comp)> pq(comp);
        for(int el:nums) map[el]++;
        for(auto [el,count]:map){
            pq.push({el,count});
            if(pq.size()>k) pq.pop();
        }
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;

    }
};
