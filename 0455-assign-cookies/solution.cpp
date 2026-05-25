class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int gn = g.size(); int sn = s.size();
        sort(g.begin(),g.end()); sort(s.begin(),s.end());
        int i=0; int j=0;
        int content_child = 0;
        while(i<gn){
            while(j < sn && s[j] < g[i]) j++;
            if(j < sn){
                content_child++;
                j++;
            }
            i++;
        }
        return content_child;
    }
};
