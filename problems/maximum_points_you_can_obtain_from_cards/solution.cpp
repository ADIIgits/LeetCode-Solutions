class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
       // since we can only choose the points from either end and that too, however we want. we wanna maximize our points. so we reverse logic. we find the subarray of length n-k that has minimum points-sum. cuz that would mean the rest of the array has maximum points-sum;
        int totalpoints = 0;
        for(int pts:nums) totalpoints+=pts;
       int pointsum = 0;
       int minpts = INT_MAX;
       int n = nums.size();

       int size = n-k;
       int p=0; int q=0;
       while(q<n){
            pointsum+=nums[q];
            //currlen = q-p;
            while((q-p+1) > size){
                pointsum-=nums[p];
                p++;
            }
            if((q-p+1)==size) minpts = min(minpts,pointsum);
            q++;
       }
       return totalpoints - minpts;
    }
};