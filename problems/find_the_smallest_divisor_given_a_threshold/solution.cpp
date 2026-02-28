class Solution {
    bool isvalid(vector<int>& nums, int mid,int threshold){
        //mid is possible smallest divisor which can make sum<threshold
        int n = nums.size();
        int divsum = 0;
        for(int el:nums){
            divsum+=ceil(el/double(mid));
        }
        return divsum<=threshold;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        //you have to find the smallest divisor, thats big enough to make the divisor sum small enough to be <=threshold
        //min divisor = min(nums) max = max(nums)
        int n = nums.size();
        int maxi = INT_MIN;
        for(int el:nums){
            maxi = max(maxi,el);
        }
        
        int minlen = maxi;
        int st = 1; int ed = maxi;
        while(st<=ed){
            int mid = st+(ed-st)/2;
            if(isvalid(nums,mid,threshold)) {
                minlen = mid;
                ed=mid-1;
            } else st=mid+1;
        }
        return minlen;
    }
};