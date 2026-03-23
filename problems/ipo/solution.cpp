class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> mincapital;
        priority_queue<int,vector<int>,less<int>> maxprofit;
        for(int i=0;i<n;i++){
            mincapital.push({capital[i],profits[i]});
        }
        int chance = 0;
        while(chance<k){
            while(!mincapital.empty() && mincapital.top().first <= w){
                maxprofit.push(mincapital.top().second);
                mincapital.pop();
            }
            if(maxprofit.empty()) break;
            w+=maxprofit.top();
            maxprofit.pop();
            chance++;
        }
        return w;
    }
};