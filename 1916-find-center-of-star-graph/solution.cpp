class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        //we know, in a start graph, that one node that shares an edge with everyone is definitely the center node + question gurantees we are given a proper real start node. meaning, if we simply find common node between even the first 2 edges, we got the center node. 
        //WAIT, what if there are more than one common node?
        //edge only exist between 2 nodes, if there are more than one common node, means, there are 2 comon nodes, meaning both edges are IDENTICALc!!, aint no graph question has identical edges !!.
        int a = edges[0][0];
        int b = edges[0][1];
        if(a==edges[1][0] || a==edges[1][1]) return a;
        if(b==edges[1][0] || b==edges[1][1]) return b;
        return -1;
    }
};
