class Solution {
public:
    vector<int> plusOne(vector<int>& dig) {
        int n=dig.size();
        int k=n-1;
        
        while(k>=0)
        {
            if(dig[k]<9)
            {
                dig[k]++;
                break;
            }
            else
            {
                dig[k]=0;
                k--;
            }
        }
        if(k<0)
        dig.insert(dig.begin(),1);

        return dig;
        
    }
};