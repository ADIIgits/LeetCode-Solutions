class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int n = digits.size();
        int q=n-1; int carry=1;
        while(q>=0){
            int sum = digits[q] + carry;
            if(sum>9){
                carry = sum/10;
                sum = sum%10;
            } else carry=0;
            ans.push_back(sum);
            q--;
        }
        if(carry!=0) ans.push_back(carry);
        for(int el:ans){
            cout<<el<<" ";
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};