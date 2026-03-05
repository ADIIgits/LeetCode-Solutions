class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //if zero>k shrink. 
        int n = nums.size();
        int maxlen = 0; int zero = 0;
        int p=0; int q=0;
        while(q<n){
            if(nums[q]==0) zero++;
            while(zero>k){
                if(nums[p]==0) zero--;
                p++;
            }
            maxlen = max(maxlen,q-p+1);
            q++; 
        }
        return maxlen;

    }
};