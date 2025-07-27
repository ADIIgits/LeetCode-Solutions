class Solution {
    public int maxProfit(int[] prices) {
        int maxprofit = Integer.MIN_VALUE;
        int n = prices.length;
        int p=0;int q=0;
        while(q<n){
            if(prices[q]<prices[p]){
                p=q;
            }
            maxprofit = Math.max(maxprofit,prices[q]-prices[p]);
            q++;
        }
        return maxprofit;
    }
}