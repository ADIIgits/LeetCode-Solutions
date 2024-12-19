class Solution {
public:
    bool isin(vector<int> &arr,int t)
    {
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==t)
            return true;
        }
        return false;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> arr;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                    if(i!=j && (nums[j]+nums[i]==target))
                    {
                        
                        arr.push_back(i);arr.push_back(j);
                        return arr;
                       
                    }
                    
            }
        }

        
        arr.push_back(-1);
        arr.push_back(-1);
        return arr;
    }
};