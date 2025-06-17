class Solution {
    public int maxProfit(int[] prices) {
        int a = 0;int b = 0; int n = prices.length; int maxi = Integer.MIN_VALUE;
        while(b<n){
            if(prices[a]>prices[b])
            a=b;
            else
            maxi = Math.max(maxi,prices[b] - prices[a]);

            b++;
        }
        return maxi;
    }
}