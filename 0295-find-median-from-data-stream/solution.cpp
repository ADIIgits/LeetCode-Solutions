class MedianFinder {
public:
    priority_queue<int,vector<int>,less<int>> first; //stores firsthalf values
    priority_queue<int,vector<int>,greater<int>> second; //stores secondhalf values
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //throw whatever comes to the first half 
        //if its greater than first.top() then it will simply become new top, 
        //if not, then good, it belongs there.
        first.push(num); //first'size +1
        // then we push new first top to second cuz at all time 
        //we wanna maintain first.top < second.top. (with size diff not being more than 1)
        second.push(first.top());  //second size +1
        first.pop(); //first's size back to normal

        //if size diff still persist, we balance em.
        //and since first size was back to normal, 
        //its evident second will be either same of bigger, so we balance em
        if(first.size() < second.size()){
            first.push(second.top());
            second.pop();
        }

    }
    
    double findMedian() {
        int n = second.size() + first.size();
        if(n%2==0) return (first.top()+second.top()) /2.0;
        else {
            if(first.size()>second.size()) return first.top();
            else return second.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
