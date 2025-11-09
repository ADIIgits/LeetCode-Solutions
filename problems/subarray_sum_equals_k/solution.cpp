class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int prefixsum = 0;
        int count = 0;
        unordered_map<int,int> freqmap;
        // freqmap[0]=1;
        for(int i=0;i<n;i++){
            prefixsum+=nums[i];

            if(prefixsum==k) count++;
            if(freqmap.find(prefixsum-k)!=freqmap.end()){
                count+=freqmap[prefixsum-k];
            }

            if(freqmap.find(prefixsum)==freqmap.end()) freqmap[prefixsum]=0;
            freqmap[prefixsum]++; 
            
        }
        return count;
    }
};