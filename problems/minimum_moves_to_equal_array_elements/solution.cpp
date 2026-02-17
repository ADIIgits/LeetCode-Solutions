class Solution {
public:
    int minMoves(vector<int>& nums) {
        //incrementing every element by 1 except one untill all equal
        //is same as decrementing one element by 1 untill all equal.
        //since im suppose to deceremnnt one value at a time. and I cant increment.
        // i can deduce. that my array will be equal when all elements will be equal to that one minimum element of the array.
        //moves = how much it takes every element to come down to minimum element.
        int sum=0;
        int mini = INT_MAX;
        for(int el:nums){
            mini = min(mini,el);
        }
        for(int el:nums){
            sum+=el-mini;
        }
        return sum;
    }
};