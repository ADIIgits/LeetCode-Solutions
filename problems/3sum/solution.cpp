class Solution {
public:
  
    // bool notin(vector<vector<int>> &vv,vector<int> &v)
    // {

    //     // sort(vv.begin(),vv.end());
    //     // sort(v.begin(),v.end());
    //     int n=vv.size();
    //     int s=0; int e=n-1;
    //     int mid=(s+e)/2;
    //     while(s<=e)
    //     {
            
    //         if(vv[mid]==v)
    //         return false;

    //         if(vv[mid]<v)
    //         {
    //             s=mid+1;
    //         }
    //         else
    //         {
    //             e=mid-1;
    //         }

    //         mid=(s+e)/2;
    //     }
    //     return true;
        
        
    // }
    vector<vector<int>> threeSum(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> vv;
        set<vector<int>> s; int j=0; int k=n-1;
        for(int i=0;i<n;i++)
        {
            
                j=i+1;
                k=n-1;
                while(j<k)
                {

                    int sum=nums[i]+nums[j]+nums[k];
                    if(sum==0)
                    {
                        s.insert({nums[i],nums[j],nums[k]});
                        j++; k--;
                    }
                    else if(sum<0)
                    {
                            j++;
                    }
                    else
                    {
                        k--;
                    }
                }
            
        }
        for(int i=0;i<s.size();i++)
        {
            vv.push_back(*next(s.begin(),i));
        }
        return vv;

        // vector< vector<int> > vv;
        // int n=nums.size();
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=i+1;j<n;j++)
        //     {
        //         for(int k=j+1;k<n;k++)
        //         {
        //             if((nums[i]+nums[j]+nums[k])==0)
        //             {
        //                 vector<int> v;
        //                 v.push_back(nums[i]);
        //                 v.push_back(nums[j]);
        //                 v.push_back(nums[k]);
        //                 if(notin(vv,v))
        //                 {
        //                     vv.push_back(v);
        //                 }
        //             }
                    
        //         }
        //     }
        // }

        // return vv;
    }
};