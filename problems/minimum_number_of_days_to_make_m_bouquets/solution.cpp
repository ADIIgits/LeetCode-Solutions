class Solution {
    int isValid(int mid,vector<int>& bloomDay,int m,int k){
        //mid is a possible minallowed day to make this work.
        int days=1; int boq=0; int adj=0;
        for(int d:bloomDay){
            if(d<=mid){
                adj++;
            } else adj=0;
            if(adj==k){
                boq++;
                adj=0;
            }
        }
        return boq>=m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        //mindays = min(blomdays) max(bloomday)
        int mini = INT_MAX; int maxi = INT_MIN;
        for(int el:bloomDay){
            mini = min(mini,el);
            maxi = max(maxi,el);
        }
        int st = mini; int ed = maxi;
        int mindays = INT_MAX;
        while(st<=ed){
            int mid = st+(ed-st)/2;
            if(isValid(mid,bloomDay,m,k)){
                mindays = min(mindays,mid);
                ed=mid-1;
            } else st = mid+1;
        }
        if(mindays==INT_MAX) return -1;
        return mindays;
    }
};