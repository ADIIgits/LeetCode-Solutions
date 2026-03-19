class Solution {
    
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        //store freq in a map, use a set for storing unique keys, put em unique {nums[i],freqcount} in pq and return em
        auto comp = [](pair<int,int>& a, pair<int,int>& b) {
            return a.second > b.second;
        };
        int n = nums.size();
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(comp)> pq(comp);
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }
        for(auto [el,count]:map){
            pq.push({el,count});
            if(pq.size()>k) pq.pop();
        }
        while(!pq.empty()){
            ans.push_back(pq.top().first); pq.pop();
        }
        return ans;

    }
};