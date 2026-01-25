class Solution {
    int beauty(vector<int> &alphas){
        int mini=INT_MAX; int maxi=INT_MIN;
        for(int el:alphas){
            if(el!=0) mini = min(mini,el);
            maxi = max(maxi,el);
        }
        if(maxi==INT_MIN || mini==INT_MAX) return 0;
        return maxi-mini;
    }
    
public:
    int beautySum(string s) {
        int n = s.length();
        int beautysum = 0;
        
        for(int i=0;i<n;i++){
            vector<int> alphas(26,0);
            for(int j=i;j<n;j++){
                alphas[s[j]-'a']++;
                beautysum+=beauty(alphas); 
            }
        }
        return beautysum;
        
    }
};