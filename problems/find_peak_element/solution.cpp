class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int st=0; int ed=n-1;
        while(st<=ed){
            int mid = st + (ed-st)/2;
            int prev=INT_MIN; int next=INT_MIN;
            if(mid!=0) prev=nums[mid-1];
            if(mid!=n-1) next=nums[mid+1];
            if(prev<nums[mid] && next<nums[mid]) return mid;
            else if(prev<=nums[mid]) st=mid+1;
            else ed=mid-1;
        }
        return 0;
    }
};