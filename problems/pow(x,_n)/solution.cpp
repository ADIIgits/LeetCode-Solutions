class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(n<0){
            if(n==INT_MIN) return myPow(x,n+1)/x;
            else return 1/myPow(x,-n);
        }
        
        double ans = myPow(x,n/2);
        ans = ans*ans;
        if(n%2==1) ans = ans*x;
        return ans;
    }
};