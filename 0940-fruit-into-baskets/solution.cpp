class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // maintain distinct count via maps, if more than k, shrink
        int n = fruits.size();
        unordered_map<int,int> map;
        int p=0; int q=0;
        int maxlen = 0;
        while(q<n){
            map[fruits[q]]++;
            while(map.size() > 2){
                map[fruits[p]]--;
                if(map[fruits[p]] <= 0) map.erase(fruits[p]);
                p++;
            }
            maxlen = max(maxlen,q-p+1);
            q++;
        }
        return maxlen;
    }
};
