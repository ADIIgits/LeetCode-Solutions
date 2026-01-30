class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        string ansstr = "";
        for(int i=0;i<n;){
            int j = i; int count=0;
            ansstr+=chars[i];
            while(j<n && chars[i]==chars[j]){
                count++;
                j++;
            }
            if(count>1){
                ansstr+=to_string(count);
                i=j;
            }
            else i++;
        }
        int p=0; int k=0;
        while(p<n && k<ansstr.length()){
            chars[p++]=ansstr[k++];
        }
        return ansstr.length();
    }
};