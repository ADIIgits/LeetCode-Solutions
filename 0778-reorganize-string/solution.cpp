class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        unordered_map<char,int> map;
        priority_queue<pair<int,char>,vector<pair<int,char>>,less<pair<int,char>>> pq;
        for(char c:s) map[c]++;
        for(auto [c,f]:map){
            pq.push({f,c});
        }
        string ans = "";
        pair<int,char> prev = {0,'#'};
        while(!pq.empty()){
            auto [count,ch] = pq.top();
            pq.pop();
            ans+=ch;
            count--;
            if(prev.first > 0) pq.push(prev);
            prev = {count,ch};
        }
        if(ans.length()!=s.length()) return "";
        return ans;
    }
};
