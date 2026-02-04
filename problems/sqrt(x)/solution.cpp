class Solution {
public:
    int mySqrt(int x) {
        int st=0; int ed=x;
        int sqrt=0;
        while(st<=ed){
            long long mid = st + (ed-st)/2;
            if(mid*mid<=x) {
                sqrt=mid;
                st=mid+1;
            }
            else ed=mid-1;
        }
        return sqrt;
    }
};