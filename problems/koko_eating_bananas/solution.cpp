class Solution {
    bool isValid(int mid,vector<int>& piles,int h){
        //mid is possible speed (banana/h) 
        int n = piles.size(); long hour=0;
        // int bananas = 0;
        for(int banana:piles){
            if(banana<mid){
                // bananas+=banana;
                hour++;
            }else {
                // bananas+=banana;
                hour+=ceil(double(banana)/double(mid));
            }
        }
        return hour<=h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //calc banana eating speed for every hour. which will be based on 
        // what is speed? dis/time, banana/h
        //min k? ). 0 bana per/h   max k? max(piles) per/h
        int maxi = INT_MIN;
        for(int el:piles) {
            maxi = max(maxi,el);
        }
        int st = 1; int ed = maxi;
        int mink = INT_MAX;
        while(st<=ed){
            int mid = st +(ed-st)/2;
            if(isValid(mid,piles,h)){
                mink = min(mink,mid);
                ed = mid-1;
            } else st=mid+1;
        }
        return mink;
    }
};