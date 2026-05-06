class Solution {
public:
    int calcaxarea_histogram(vector<vector<int>> histos,int i){
		
        int m = histos[0].size();
        stack<int> st;
        vector<int> arr(histos[i]);
        int maxarea = 0;
        for(int j=0;j<=m;j++){
            while(!st.empty() && (j==m || arr[st.top()] > arr[j])){
                int curr = st.top();
                int nextsmaller = j;
                st.pop();
                int prevsmaller = st.empty() ? -1 : st.top();
                int area = (nextsmaller - prevsmaller - 1) * arr[curr];
                maxarea = max(maxarea,area);
            }
            if(j<m) st.push(j);
        }
        return maxarea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
		    //the idea is to imagine histograms. 
		    //we know how to calculate maxarea in a histogram, this matrix is also, 
		    //in a way a histogram. more like, overlapping histograms.
		    //row 0 is a histogram
		    //row 1 is a histogram with heights reaching till row 0.
		    //row 2 is a histogram with heights reaching till row 0.
		    //row 3 is a histogram with heights reaching till row 0. and so on.
		    
        int n = matrix.size(); int m = matrix[0].size();
        vector<vector<int>> histos(n,vector<int>(m,0));
        int maxarea = 0;
        //we gonna through each column and sum em up
        for(int j=0;j<m;j++){
            int sum = 0;
            for(int i=0;i<n;i++){
	              //sum up only if current cell is non zero. and mark sum along da way.
                if(matrix[i][j]=='1'){
                    sum++;
                    histos[i][j] = sum;
                } else { //otherwise reset sum. cuz height break. mark 0.
                    sum = 0;
                    histos[i][j] = 0;
                }
            }
        }
        for(int i=0;i<n;i++){
            maxarea = max(maxarea,calcaxarea_histogram(histos,i));
        }
        return maxarea;
    }

};
