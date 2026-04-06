class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        unordered_map<int,int> map;
        vector<string> ans;
        vector<int> sortedarr(score);
        sort(sortedarr.begin(),sortedarr.end(),greater());
        for(int i=0;i<n;i++){
            //storing em rank
            map[sortedarr[i]]=i;
        }
        for(int i=0;i<n;i++){
            if(map[score[i]]==0) ans.push_back("Gold Medal");
            else if(map[score[i]]==1) ans.push_back("Silver Medal");
            else if(map[score[i]]==2) ans.push_back("Bronze Medal");
            else ans.push_back(to_string(map[score[i]]+1));
        }
        return ans;
        
    }
};
