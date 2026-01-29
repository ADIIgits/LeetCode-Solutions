class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int count=0;
        double sum = 0; 
        for(int i=0;i<k;i++) sum+=arr[i];
        double avg = sum/double(k);
        if(avg>=threshold) count++;
        for(int i=k;i<n;i++){
            sum-=arr[i-k];
            sum+=arr[i];
            avg = sum/double(k);
            if(avg>=threshold) count++;
        }
        return count;
    }
};