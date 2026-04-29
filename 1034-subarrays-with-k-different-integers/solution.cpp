class Solution {
public:
    int countgood(vector<int>& nums, int k){
        int n = nums.size();
        unordered_map<int,int> map;
        int p=0; int q=0;
        int count=0;
        while(q<n){
            map[nums[q]]++;
            while(map.size() > k){
                map[nums[p]]--;
                if(map[nums[p]]==0) map.erase(nums[p]);
                p++;
            }
            count+=q-p;
            q++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countgood(nums,k) - countgood(nums,k-1);
    }
};
