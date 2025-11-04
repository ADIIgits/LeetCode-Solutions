class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1 ) return n;
        int curr=1; int prev=0; int sum=0;
        for(int i=1;i<n;i++){
            sum = curr+prev;
            prev=curr;
            curr=sum;
        }
        return sum;
    }
};