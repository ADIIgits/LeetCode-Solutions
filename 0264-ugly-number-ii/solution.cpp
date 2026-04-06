class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long,vector<long>,greater<long>> pq;
        set<long> seen;
        pq.push(1);
        seen.insert(1);
        int j=0;
        long uglynum = 1;
        while(j<n){
            uglynum = pq.top();
            pq.pop();
            long twomul = uglynum*2;
            long threemul = uglynum*3;
            long fivemul = uglynum*5;
            if(seen.count(twomul)==0){
                pq.push(twomul);
                seen.insert(twomul);
            } 
            if(seen.count(threemul)==0){
                pq.push(threemul);
                seen.insert(threemul);
            }
            if(seen.count(fivemul)==0){
                pq.push(fivemul);
                seen.insert(fivemul);
            }
            j++;
        }
        return uglynum;
    }
};
