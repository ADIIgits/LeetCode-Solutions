class Solution {
    ArrayList<Integer> sumarr = new ArrayList<>();
    public boolean isHappy(int n) {
        int num=n; int sum=0;
        
        while(num>0){
            int d = num%10;
            sum+=Math.pow(d,2);
            num=num/10;
        }
        if(sum==1)
        return true;
        else{
            if(sumarr.contains(sum))
            return false;
            else{
            sumarr.add(sum);
            return isHappy(sum);}
        }

        
    }
}