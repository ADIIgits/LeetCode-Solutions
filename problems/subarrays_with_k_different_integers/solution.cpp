class Solution {
    int calcsub(vector<int>& nums, int k){
        unordered_map<int,int> map;
        // unordered_set<int> distinct; you dont need it, cuz map.size() already gives you that. distinct. remeber.
        int n = nums.size();
        int p=0; int q=0;
        int count=0;
        while(q<n){
            map[nums[q]]++;
            while(map.size()>k){
                map[nums[p]]--;
                if(map[nums[p]]<=0) map.erase(nums[p]);
                p++;
            }
            if(map.size()<=k) count+=(q-p+1);
            q++;
        }
        return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return calcsub(nums,k) - calcsub(nums,k-1);
    }
};