class Solution {
    
public:
    double myPow(double x, int n) {
        
        long bn = n;
        double ans = 1;
        if(n<0){
            x=1/x;
            bn=-bn;
        }
        while(bn>0){
            int d = bn%2;
            if(d==1){
                ans*=x;
            }
            x*=x;
            bn=bn/2;
        }
        return ans;

    }
};