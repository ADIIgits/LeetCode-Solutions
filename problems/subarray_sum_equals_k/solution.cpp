class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count=0;
        int prefixsum=0;
        unordered_map<int,int> map; //(subsum,freq)
        for(int i=0;i<n;i++){
            prefixsum+=nums[i];
            
            if(prefixsum==k) count++;
            int comp = prefixsum-k;
            if(map.find(comp)!=map.end()) count+=map[comp];

            map[prefixsum]++;
        }
        return count;
    }
};