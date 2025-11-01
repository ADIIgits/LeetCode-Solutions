class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate=nums[0];
        int n=nums.size();
        int count=0;
        for(int el:nums){
            if(count<=0) candidate=el;
            if(candidate==el) count++;
            else count--;
            
        }
        return candidate;
    }
};