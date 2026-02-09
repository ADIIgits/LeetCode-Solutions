class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        queue<int> que;
        for(int el:tickets) que.push(el); int i=k; int time=0;
        while(tickets[k]>0){
            if(i==0){
                tickets[k]--;
                i=que.size();
            }
            int data = que.front();
            que.pop();
            if(data-1 > 0 )que.push(data-1);
            i--;
            time++;
        }
        return time;
    }
};