class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> map; //el,count
        vector<int> ans; //el,count
        for(int i=0;i<n;i++){
            if(map.find(nums[i])!=map.end()) map[nums[i]]++;
            else map[nums[i]]=1;

            if(map[nums[i]]>n/3 && find(ans.begin(),ans.end(),nums[i])==ans.end()) ans.push_back(nums[i]);
        }
        return ans;
    }
};