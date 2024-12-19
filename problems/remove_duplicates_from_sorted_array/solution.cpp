class Solution {
public:

    bool notin(vector<int> &v,int t)
    {
        // for(int i=0;i<v.size();i++)
        // {
        //     if(v[i]==t)
        //     return false;
        // }
        // return true;
        int s=0; int e=v.size()-1;
        int mid=(s+e)/2;
        while(s<=e)
        {
            mid=(s+e)/2;

            if(v[mid]==t)
            {
                return false;
            }

            if(t<v[mid])
            {
                e=mid - 1;
            }
            else
            {
                s=mid+1; 
            }
            // mid=(s+e)/2;
        }

        return true;
    }
    int removeDuplicates(vector<int>& nums) {
        vector<int> v;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(notin(v,nums[i]))
            {
                v.push_back(nums[i]);
            }
            
        }

        nums.resize(0);
        for(int i=0;i<v.size();i++)
        {
            nums.push_back(v[i]);
        }

        return v.size();
    }
};