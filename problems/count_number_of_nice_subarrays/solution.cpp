class Solution {
    int countgood(vector<int>& nums, int k){
        int n = nums.size();
        int nodds = 0; int count=0;
        int p=0; int q=0;
        while(q<n){
            if(nums[q]%2!=0) nodds++;
            
            while(nodds>k){
                if(nums[p]%2!=0) nodds--; 
                p++;
            }
            int currlen = q-p+1;
            if(nodds<=k) count+=currlen;
            q++;
        }
        return count;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        return countgood(nums,k)-countgood(nums,k-1);
    }
};