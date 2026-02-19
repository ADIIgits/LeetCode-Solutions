class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int n = cp.size();
        //goal is to find minsum subarray of size n-k.
        int totalsum = 0;
        for(int i=0;i<n;i++) totalsum+=cp[i];
        int sum=0; int minsum = totalsum;
        int p=0;int q=0;
        while(q<n){
            sum+=cp[q];
            while(q-p+1>n-k){
                sum-=cp[p];
                p++;
            }
            if(q-p+1==n-k) minsum = min(minsum,sum);
            q++;
        }
        return totalsum-minsum;
    }
};