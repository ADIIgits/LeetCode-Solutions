class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 0;
        int p = 0; int q=n-1;
        while(p<=q){
            int prev = INT_MIN; int next = INT_MIN;
            int mid = p + (q-p)/2;

            if(mid!=0) prev = nums[mid-1];
            if(mid!=n-1) next = nums[mid+1];

            if(prev<nums[mid] && nums[mid]>next) return mid;
            else if( nums[mid]==INT_MIN || prev<nums[mid]) p = mid+1;
            else q = mid-1;
        }
        return -1;

    }
};