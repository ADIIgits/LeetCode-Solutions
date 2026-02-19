class Solution {
    int goodsub(vector<int>& nums, int k){
        int n = nums.size();
        int count=0;
        int p=0; int q=0;
        unordered_map<int,int> freq;
        while(q<n){
            freq[nums[q]]++;
            
            while(p<q && freq.size()>k){
                freq[nums[p]]--;
                if(freq[nums[p]]==0) freq.erase(nums[p]);
                p++;
            }
            if(freq.size()<=k) count += q-p+1;
            q++;
        }
        cout<<count<<" ";
        return count;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return goodsub(nums,k) - goodsub(nums,k-1);
    }
};