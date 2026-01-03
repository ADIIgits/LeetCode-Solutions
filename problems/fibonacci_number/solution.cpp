class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1) return n;
        vector<int> fibarr(n+1,-1);
        fibarr[0]=0;
        fibarr[1]=1;
        for(int i=2;i<=n;i++){
            fibarr[i] = fibarr[i-1]+fibarr[i-2];
        }
        return fibarr[n];
    }
};