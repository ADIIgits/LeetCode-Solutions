class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> map;
        for(string word:words){
            map[word]++;
        }
        const auto comp = [](const pair<string,int> &a, const pair<string,int> &b){
            if(a.second==b.second) return a.first < b.first;
            return  a.second > b.second;
        };
        priority_queue<pair<string,int>,vector<pair<string,int>>, decltype(comp)> pq(comp);
        for(auto pair:map){
            pq.push(pair);
            if(pq.size()>k) pq.pop();
        }
        vector<string> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};