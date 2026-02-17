class Solution {
    bool isValid(vector<int>& nums, int mid, int k){
        //mid is largest possible larsum. no sum should be greater than larsum
        int sum=0;
        int split = 0;
        for(int el:nums){
            if(sum+el>mid){
                split++; //count the splits made, not the subarrays fromed. 
                sum=el;
            } else sum+=el;
        }
        split++; // cuz no of subarrays = no of splits + 1.
        return split<=k; //can we divide subarray into atmost k parts? NOT can we divide in atleast k parts. 
    }
public:
    int splitArray(vector<int>& nums, int k) {
        //min sum-> 0 maxsum = sum of all.
        int sumi = 0; int maxi = INT_MIN;
        for(int el:nums) {
            maxi = max(maxi,el);
            sumi+=el;
        }
        int st = maxi; int ed = sumi;
        int minlarsum = sumi;
        while(st<=ed){
            int mid = st + (ed-st)/2;
            if(isValid(nums,mid,k)){
                minlarsum = mid;
                ed = mid-1; 
            } else st = mid+1;
        }
        return minlarsum;
    }
};