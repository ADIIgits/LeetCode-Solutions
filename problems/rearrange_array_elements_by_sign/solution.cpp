class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        vector<int> pos;
        vector<int> neg;
        for(int el:nums){
            if(el<0) neg.push_back(el);
            else if(el>=0) pos.push_back(el);
        }
        int n = pos.size(); //neg.size() is also same as this.
        for(int i=0;i<n;i++){
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }
        return ans;
    }
};