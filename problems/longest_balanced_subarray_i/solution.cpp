class Solution {
    // bool check(vector<int>& nums,int i,int j){
    //     int odd = 0; int even = 0;
    //     unordered_map<int,int> odds; unordered_map<int,int> evens; 
    //     for(int k=i;k<=j;k++){
    //         if(nums[k]%2==0) evens[nums[k]]++;
    //         else odds[nums[k]]++;
    //     }
    //     return odds.size()==evens.size();
    // }
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxlen = 0;
        for(int i=0;i<n;i++){
            unordered_map<int,int> odds; unordered_map<int,int> evens; 
            for(int j=i;j<n;j++){
                if(nums[j]%2==0) evens[nums[j]]++;
                else odds[nums[j]]++;
                
                if(odds.size()==evens.size()) maxlen = max(maxlen,j-i+1);
            }
        }
        return maxlen;
    }
};