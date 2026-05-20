class Solution {
public:
    int maxJump(vector<int>& stones) {
        //since its in strictly accending order, worst strantegy would be to simply use/pick every stone whiling going and in the return trip you will have to make the biggest jump, from largest to smallest.
        // kinda reverse logic, since array is sorted, there is somekind of uniformity. 
        //imagine array as stapoo, in ascending order, you gotta minimize the largest jump.
        //you will pick alternate stones !! so in return you have other alternate stones. 
        //and jump wont be so big.
        int n = stones.size();
        int maxjump = 0;
        if(n==2) return stones[1]-stones[0];
        if(n<2) return stones[0];
        for(int i=2;i<n;i++){
            maxjump = max(maxjump,abs(stones[i]-stones[i-2]));
        }
        return maxjump;
    }
};
