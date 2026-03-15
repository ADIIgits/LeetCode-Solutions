class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        int ans = 0;
        int maxjump = 0;
        if(n==2) return stones[1]-stones[0];
        if(n<2) return stones[0];
        for(int i=2;i<n;i++){
            maxjump = max(maxjump,abs(stones[i]-stones[i-2]));
        }
        return maxjump;
    }
};