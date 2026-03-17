class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        //store {score,pos} in a map
        // store em elements in heap
        // traverse em heap access em element's pos using map, and in that pos in ans array fit da element
        int n = score.size();
        vector<string> ans(n," ");
        unordered_map<int,int> map;
        for(int i=0;i<n;i++) map[score[i]]=i;
        
        priority_queue<int,vector<int>,less<int>> pq;
        for(int el:score) pq.push(el);
        int k = n;
        while(!pq.empty()){
            int pos = n-k+1;
            if(pos==1) ans[map[pq.top()]] = "Gold Medal";
            else if(pos==2) ans[map[pq.top()]] = "Silver Medal";
            else if(pos==3) ans[map[pq.top()]] = "Bronze Medal";
            else ans[map[pq.top()]] = to_string(pos);
            pq.pop();
            k--;
        }
        return ans;
    }
};