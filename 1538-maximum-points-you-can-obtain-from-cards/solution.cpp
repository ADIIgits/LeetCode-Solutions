class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int size = n-k;
        int p=0; int q=0;
        int totalpts = 0;
        int minpts = INT_MAX;
        int pts = 0;
        for(int i=0;i<size;i++){
            pts+=cardPoints[i];
            totalpts += cardPoints[i];
        }
        minpts = pts;
        for(int i=size;i<n;i++){
            pts-=cardPoints[i-size];
            pts+=cardPoints[i];
            minpts = min(minpts,pts);

            totalpts += cardPoints[i];
        }
        return totalpts - minpts;
    }
};
