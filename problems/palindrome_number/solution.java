class Solution {
    public boolean isPalindrome(int x) {

        // String str = Integer.toString(x);
        // int n = str.length();
        // int f=1;
        // for(int i=0;i<n;i++)
        // {
        //     if(!(str.charAt(i)==str.charAt(n-i-1)))
        //     f=0;
        // }
        // return f==1;

        // String numstr = Integer.toString(x);
        // String rev = new StringBuilder(numstr).reverse().toString();

        // return numstr.equals(rev);
    //}

        if(x<0)
        return false;

        int c=0; long rev=0;
        // for(int i=x;i>0;i=i/10)
        // {
        //     c++;

        // }
        // c--;
        for(int i=x;i>0;i=i/10)
        {
            int d = i%10;
            rev=rev*10+d;
            //c--;

        }
        return rev==x;
    }
}