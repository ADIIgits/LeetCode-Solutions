class Solution {
    int gcd(int a,int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX; int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            mini = min(mini,nums[i]);
            maxi = max(maxi,nums[i]);
        }
        return gcd(maxi,mini);
    }
};