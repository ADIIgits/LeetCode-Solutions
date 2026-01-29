class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int maxlen = INT_MIN;
        unordered_map<int,int> distincts;
        int i=0; int j=0;
        while(j<n){

            distincts[fruits[j]]++;

            while(distincts.size()>2){
                distincts[fruits[i]]--;
                if(distincts[fruits[i]]<=0) distincts.erase(fruits[i]);
                i++;
            }
            maxlen = max(maxlen,j-i+1);
            j++;
        }
        return maxlen;
    }
};