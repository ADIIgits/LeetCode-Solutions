class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int element=0;
        for(int el:nums) element^=el;
        return element;
    }
};