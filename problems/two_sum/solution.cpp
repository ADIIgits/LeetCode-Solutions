class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> cache;
        for(int i=0;i<n;i++){
            int compliment = target-nums[i];
            auto hit = cache.find(compliment);
            if(hit!=cache.end()){
                return {hit->second,i};
            }
            else cache[nums[i]]=i;
        }
        return {-1,-1};
        
    }
};