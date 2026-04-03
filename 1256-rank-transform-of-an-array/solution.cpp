class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp=arr;
        vector<int> ans;
        sort(temp.begin(),temp.end());
        temp.erase(unique(temp.begin(),temp.end()),temp.end());
        unordered_map<int,int> map;
        for(int i=0;i<temp.size();i++) map[temp[i]]=i;
        for(int i=0;i<n;i++){
            ans.push_back(map[arr[i]]+1);
        }
        return ans;
    }
};
