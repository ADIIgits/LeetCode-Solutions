class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        //1 milra age bado, 0 milra count++, agar count > k, shrink
        int n = nums.size();
        int maxlen = 0;
        // unordered_map<int,int> map;
        int p=0; int q=0;
        int chance = 0;
        while(q<n){
            if(nums[q]==0) chance++;
            while(chance > k){
                if(nums[p]==0) chance--;
                p++;
            }
            maxlen = max(maxlen,q-p+1);
            q++;
        }
        return maxlen;
    }
};
