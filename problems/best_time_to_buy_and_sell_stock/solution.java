class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int p=0; int q=0; int finalprice = Integer.MIN_VALUE;
        while(q<n){
            if(prices[p]>prices[q]) p=q;
            else finalprice = Math.max(finalprice,prices[q]-prices[p]);
            q++;
        }
        
      
        return finalprice;
    }
}