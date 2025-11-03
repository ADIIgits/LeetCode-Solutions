class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(); int count=0;
        int p=0;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[p]){
                p++;
                nums[p]=nums[i];
            }
        }
        
        return p+1;
        
    }
};