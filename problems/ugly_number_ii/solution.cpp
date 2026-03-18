class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long,vector<long>,greater<long>> pq;
        set<long> seen;
        pq.push(1);
        seen.insert(1);
        int ugly = 0;
        long el = 1;
        while(ugly<n){
            el = pq.top(); //confirmed ugly number
            pq.pop();

            long num2 = el*2; //future candidate
            long num3 = el*3; //future candidate
            long num5 = el*5; //future candidate
            if(seen.find(num2)==seen.end()){
                //storing future candidate in heap
                pq.push(num2);
                seen.insert(num2);
            } 
            if(seen.find(num3)==seen.end()){
                //storing future candidate in heap
                pq.push(num3);
                seen.insert(num3);
            }
            if(seen.find(num5)==seen.end()){
                //storing future candidate in heap
                pq.push(num5);
                seen.insert(num5);
            }
            ugly++; //since there is only one confirmed ugly number in each iteration, we simply ++
        }
        return el;

    }
};