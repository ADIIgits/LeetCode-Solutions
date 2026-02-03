class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int p=0; int q=0;
        int chances=0;
        int maxones = INT_MIN;
        while(q<n){
            if(nums[q]==0){
                chances++;
            }
            while(chances > k){
                if(nums[p]==0){
                    chances--;
                }
                p++;
            }
            maxones = max(maxones,q-p+1);
            q++;
        }
        return maxones;
    }
};