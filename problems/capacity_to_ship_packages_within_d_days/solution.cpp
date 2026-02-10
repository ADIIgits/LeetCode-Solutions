class Solution {
    bool isValid(int poscap,int days,vector<int>& weights){
        int d=1; int cap=0;
        for(int weight:weights){
            if(weight>poscap) return false;
            if(cap+weight>poscap){
                d++;
                cap=weight;
            }
            else cap+=weight;
        }
        return days>=d;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        //min capacity -> max(weightsbegin,weightsend); max capacity->sum of weights.
        int maxi = INT_MIN; int sum=0;
        
        for(int el:weights){
            maxi = max(maxi,el);
            sum+=el;
        }
        int mincap=sum;
        int st=maxi; int ed = sum; //range of possible capacities
        while(st<=ed){
            int mid = st + (ed-st)/2;
            if(isValid(mid,days,weights)){
                mincap = min(mincap,mid);
                ed=mid-1;
            } else st=mid+1;
        }
        return mincap;
    }
};