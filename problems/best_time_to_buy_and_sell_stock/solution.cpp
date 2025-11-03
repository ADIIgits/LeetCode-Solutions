class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int p=0; int q=0;
        int maxprofit = 0;
        while(q<n){
            if(prices[q]<prices[p]) p=q;
            else{
                //means prices[p]<prices[q] higher SP
                //so we calc maxprofit here itself
                maxprofit = max(maxprofit,prices[q]-prices[p]);
            }
            q++; 
        }
        return maxprofit;

    }
};