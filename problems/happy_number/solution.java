class Solution {
    class comp{
        static boolean in(int sum,int[] sumarr,int k)
        {
            for(int i=0;i<k;i++)
            {
                if(sumarr[i]==sum)
                return true;
            }
            return false;
        }
    }
    public boolean isHappy(int n) {
        int sum = 0;
        // int[] sumarr = new int[100];
        HashSet<Integer> sumarr = new HashSet<>();
        int k=0;
        while(sum!=1)
        {
            for(int i=n;i>0;i=i/10)
            {
                int d = i%10;
                sum+=d*d;
            }
            if(sum==1)
            return true;

            if(sumarr.contains(sum))
            break;
            else
            sumarr.add(sum);
            // sumarr[k++]=sum;

            n=sum;
            sum=0;

        }
        return false;
    }
}