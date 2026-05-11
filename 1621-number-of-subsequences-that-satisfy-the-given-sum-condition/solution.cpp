class Solution {
public:
    int mod = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        //2 key observations.
        // 1. return an integer count. thus, ans doees not depend on the order of elements. 
        // does calculation depend on order?
        // 2. since for every subsequence we only want its minimum and maximum, so no, 
        // we dont necesarily need order of elements
        // whats the best way to get max and min in an array(or any subarray or subsequenc even)?
        //fkin sort it !!
        //
        int n = nums.size();
        long count=0;
        sort(nums.begin(),nums.end());
        vector<int> power(n);
        power[0]=1;
        for(int i=1;i<n;i++){
            power[i] = (power[i-1]*2)%mod;
        }
        int st = 0; int ed = n-1;
        while(st<=ed){
            int sum = nums[st]+nums[ed];
            if(sum<=target){
                //why not simply count++? cuz for every min and max that satisfy, 
                //every subarray between it satisfy as well. and since we want 
                //subsequence count not subarray count, 
                //we do count for every subarray where an element could be included or excluded.
                //thus 2 ^ ed-st
                count = count + power[ed-st];
                st++;
            }
            else ed--;
        }
        return count%mod;

    }
};
