class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int maxprod = 0; int prefix=1; int suffix=1;
        for(int i=0;i<n;i++){
            if(prefix==0) prefix=1;
            if(suffix==0) suffix=1;
            prefix*=nums[i];
            suffix*=nums[n-i-1];
            maxprod = max(maxprod,(max(prefix,suffix)));
        }
        return maxprod;
    }
    
};