class Solution {
public:
    int countnice(vector<int>& nums, int k) {
        int n = nums.size();
        int p=0; int q=0;
        int count = 0; int odd=0;
        while(q<n){
            if(nums[q]%2!=0) odd++;
            while(odd > k){
                if(nums[p]%2!=0) odd--;
                p++;
            }
            if(odd <=k) count+=q-p+1;
            q++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return countnice(nums,k) - countnice(nums,k-1);
    }
};
