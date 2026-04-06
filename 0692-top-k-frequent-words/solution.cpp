class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string,int> map;
        for(string word:words) map[word]++;
        auto comp = [](const pair<string,int> &a,const pair<string,int> &b){
            if(a.second==b.second) return a.first < b.first; 
            return a.second > b.second;
        };
        priority_queue<pair<string,int>, vector<pair<string,int>>, decltype(comp)> pq(comp);
        for(auto [el,count]:map){
            pq.push({el,count});
            if(pq.size()>k) pq.pop();
        }
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
