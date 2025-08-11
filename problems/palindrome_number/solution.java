class Solution {
    public boolean isPalindrome(int xmen) {
        int x = xmen;
        if(x<0) return false;
        int revx = 0;
        while(x!=0){
            int d = x%10;
            revx = revx*10+d;
            x=x/10;
        }
        
        return xmen==revx;
    }
}