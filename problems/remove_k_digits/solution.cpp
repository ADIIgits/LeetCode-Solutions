class Solution {
public:
    string removeKdigits(string nums, int k) {
        

        string st = "";
        int n = nums.size();
        for(int i=0;i<n;i++){
            char curr = nums[i];
            while(!st.empty() && st.back()>nums[i] && k>0){
                st.pop_back();
                k--;
            }
            st.push_back(nums[i]);
        }
        int i=0;
        while(!st.empty() && k>0){
            st.pop_back(); k--;
        }
        while(st[i]=='0')i++;
        st = st.substr(i);
        if(st=="") return "0";
        else return st;

    }
};