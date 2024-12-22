class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> vv;
        set<vector<int>> s;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                    int k=j+1;
                    int l=n-1;
                    while(k<l)
                    {
                        
                        if((long long)nums[i]+(long long)nums[j]+(long long)nums[k]+(long long)nums[l]==target)
                        {
                            s.insert({nums[i],nums[j],nums[k],nums[l]});
                            k++; l--;
                        }
                        else if((long long)nums[i]+(long long)nums[j]+(long long)nums[k]+(long long)nums[l]<target)
                        {
                            k++;
                        }
                        else
                        {
                            l--;
                        }
                    }
            }
        }

        for(int i=0;i<s.size();i++)
        {
            vv.push_back(*next(s.begin(),i));
        }
        return vv;
    }
};