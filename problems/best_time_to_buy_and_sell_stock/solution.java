class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int maxi = Integer.MIN_VALUE; 
        int p=0; int q=0;
        while(q<n){
            maxi = Math.max(maxi,prices[q]-prices[p]);
            if(prices[q]<prices[p]) p=q;

            q++;
        }
        return maxi;
    }
}