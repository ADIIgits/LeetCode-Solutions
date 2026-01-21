class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int p=0; int q=n-1; int r=0; int c=0;
        while(r<n){
            if(nums[r]!=0) nums[p++] = nums[r];
            else c++;

            r++;
        }
        for(int i=n-c;i<n;i++) nums[i]=0; 



        
    }
};