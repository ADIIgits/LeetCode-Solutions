class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        int s1=nums[0];
        int smol = 100;
        int secondsmol = 101;
        int mini = INT_MAX;
        for(int i=1;i<n;i++){
            if(nums[i]<smol){
                secondsmol = smol;
                smol = nums[i];
            }
            else if(nums[i]<secondsmol) secondsmol = nums[i];
        }
        return s1+smol+secondsmol;

    }
};