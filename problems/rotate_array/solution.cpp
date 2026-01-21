class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k=k%n;
        if(n<=1) return;
        vector<int> nm(n); int p=0;
        for(int i=n-k;i<n;i++){
            nm[p++]=nums[i];
        }
        for(int i=0;i<n-k;i++){
            nm[p++]=nums[i];
        }
        nums=nm;
    }
};