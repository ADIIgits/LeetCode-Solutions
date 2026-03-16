class Solution {
public:
    string frequencySort(string s) {
        //make map with {char,freq}
        //sort by freq
        //build ans and return
        int n = s.length();
        unordered_map<int,int> map;
        for(int i=0;i<n;i++){
            map[s[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>> pq;
        for(int i=0;i<n;i++){
            pq.push({map[s[i]],s[i]});
        }
        string ans = "";
        while(!pq.empty()){
            ans+= (char) pq.top().second;
            pq.pop();
        }
        return ans;
    }
};